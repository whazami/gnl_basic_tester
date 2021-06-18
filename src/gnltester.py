import subprocess
import filecmp
import sys

errors = [0, 0, 0]
clearLine = False

def clearPreviousLine():
	sys.stdout.write("\033[F") # Back to previous line 
	sys.stdout.write("\033[K") # Clear line

def static_vars(**kwargs):
    def decorate(func):
        for k in kwargs:
            setattr(func, k, kwargs[k])
        return func
    return decorate

def printProgress(current, end):
	global clearLine
	if clearLine:
		clearPreviousLine()
		clearPreviousLine()
	print(str(current) + "/" + str(end) + "\n")
	clearLine = True

def test(bufferSize, part):
	subprocess.call("gcc -Wall -Wextra -Werror -D BUFFER_SIZE=" + str(bufferSize) + " src/main.c ../get_next_line.c ../get_next_line_utils.c", shell=True)
	subprocess.call("./a.out | cat -e > output.txt", shell=True)
	if filecmp.cmp("output.txt", "txt/good_output.txt", shallow=False) is False:
		global clearLine
		clearLine = False
		print("---------------------------------------")
		print("Doesn't work with BUFFER_SIZE=" + str(bufferSize))
		print("Output:")
		subprocess.call("cat output.txt", shell=True)
		print("\n")
		print("Expected:")
		subprocess.call("cat txt/good_output.txt", shell=True)
		print("---------------------------------------\n")
		errors[part - 1] += 1
		return (0)
	subprocess.call("rm a.out output.txt", shell=True)
	return (1)

print("Compiling C files...")
print("Part 1:")
for i in range(1, 51):
	if test(i, 1):
		printProgress(i - errors[0], 50)
print("Part 2:")
clearLine = False
for i in range(100, 2001, 100):
	if test(i, 2):
		printProgress(int(i / 100) - errors[1], 20)
print("Part 3:")
clearLine = False
for i in range(100000, 500001, 100000):
	if test(i, 3):
		printProgress(int(i / 100000) - errors[2], 5)
print("Done.")
