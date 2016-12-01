#include <iostream>
#include "xmlGenerator.h"

using namespace std;

int main()
{
	xmlGenerator::XMLGenerator xmlGenerator;

	xmlNodePtr n;
	xmlDocPtr doc;
	xmlChar *xmlBuf;
	int bufSize;

	doc = xmlNewDoc(BAD_CAST "1.0");
	n = xmlNewNode(NULL, BAD_CAST "root");
	xmlNodeSetContent(n, BAD_CAST "content");
	xmlDocSetRootElement(doc, n);

	xmlDocDumpFormatMemory(doc, &xmlBuf, &bufSize, 1);
	cout << xmlBuf << endl;

	xmlFree(xmlBuf);
	xmlFreeDoc(doc);

	return 1;
}
