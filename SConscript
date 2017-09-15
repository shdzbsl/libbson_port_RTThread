Import('RTT_ROOT')
Import('rtconfig')
from building import *

cwd     = os.path.join(str(Dir('#')), 'BSON')

# add the general APPs.
src = Split("""
	bcon.c 
	bson.c 
	bson-clock.c 
	bson-decimal128.c 
	bson-iter.c 
	bson-iso8601.c 
	bson-json.c 
	bson-keys.c 
	bson-md5.c 
	bson-memory.c 
	bson-oid.c 
	bson-reader.c 
	bson-string.c 
	bson-timegm.c 
	bson-utf8.c 
	bson-value.c 
	bson-version-functions.c 
	bson-writer.c
	
	jsonsl.c

""")

CPPPATH = [cwd, str(Dir('#'))]

group = DefineGroup('BSON', src, depend = [''], CPPPATH = CPPPATH)

Return('group')
