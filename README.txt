This is a RTThread port of mongodb/libbson, 
you can just copy this folder to RTThread project.  

More detail about BSON, you can see: 
		https://github.com/mongodb/libbson/tree/master/
		http://www.bsonspec.org/
		
If you want port it to other RTOS or compiler , you need modify the bson_macros.h
Some test demo is in the folder "test", good luck !

If you want entire function of bson, use this file list :
{
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
}


If you want a basic function of bson, you can use this:
{
	bcon.c 
	bson.c 
//	bson-clock.c  
	bson-decimal128.c 
	bson-iter.c 
	bson-iso8601.c 
//	bson-json.c 
	bson-keys.c 
//	bson-md5.c 
	bson-memory.c 
	bson-oid.c 
//	bson-reader.c 
	bson-string.c 
	bson-timegm.c 
	bson-utf8.c 
	bson-value.c 
//	bson-version-functions.c 
//	bson-writer.c
//	jsonsl.c
}
