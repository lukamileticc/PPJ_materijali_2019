import re
import sys
import os

if len(sys.argv) > 1:
	homedir = sys.argv[1]
else:
	homedir = '.'

re_dir = re.compile(r'm[mnvlri]\d{5}$')

re_file = re.compile(r'\d+\.(java|c|cpp|pas)$')

for f in os.listdir(homedir):
	
	#pamtimo putanju
	dirPath = os.path.join(homedir,f);

	m = re_dir.match(f)
	
	if os.path.isdir(dirPath) and m is not None:
		
		print("\n" + m.group())
		
		for sf in os.listdir(dirPath):

			path = os.path.join(dirPath,sf)
			
			m = re_file.match(sf)
			
			if os.path.isfile(path) and m is not None:
				print("\t" + m.group())
			


