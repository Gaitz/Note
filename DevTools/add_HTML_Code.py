from os import listdir
from sys import argv

htmlCode = """
  </body>
</html>
"""
print("argv[1] " + argv[1])

relativePath = argv[1]
for files in listdir(argv[1]): # get file name only
	sourcePath = relativePath + files # get the path
	print("sourcePath " + sourcePath)
	with open(sourcePath, 'a') as sourceFile: # append
		sourceFile.write(htmlCode)
