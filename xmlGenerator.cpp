#include <iostream>
#include "xmlGenerator.h"

using namespace std;

namespace xmlGenerator
{

void BaseXMLGenerator::setConditions(conditions condi)
{

}

conditions BaseXMLGenerator::getConditions()
{
	return condition;
}

void BaseXMLGenerator::setXMLData(vector<pair<string, string> > meta, vector<string> data)
{
	cout << "BaseXMlGenerator setXMLData!" << endl;

}

string BaseXMLGenerator::generateXMLDocument()
{
	return "aaa";
}

void XMLResult::setConditions(conditions condi)
{
//	conditions = condi;
}

conditions XMLResult::getConditions()
{
	return xmlGenerator->condition;
}

void XMLResult::setXMLData(vector<pair<string, string> > meta, vector<string> data)
{
	cout << "XMLResult setXMLData!" << endl;

	// traverse for upper class
	xmlGenerator->setXMLData(meta, data);
}

string XMLResult::generateXMLDocument()
{
	cout << "XMLResult generateXMLDocument!" << endl;

	// print out for upper class
	xmlDocument = xmlGenerator->generateXMLDocument();
	return xmlDocument;
}

void XMLSchema::setConditions(conditions condi)
{
//	conditions = condi;
}

conditions XMLSchema::getConditions()
{
	return condition;
}

void XMLSchema::setXMLData(vector<pair<string, string> > meta, vector<string> data)
{
	cout << "XMLSchema setXMLData!" << endl;

	// traverse for upper class
	XMLResult::setXMLData(meta, data);

	// traverse for this class
	vector<string>::iterator itr;

	int count = 0;
	for (itr = data.begin(); itr != data.end(); ++itr)
	{
		cout << ++count << " " << *itr << endl;
		xmlDocument += *itr;
		xmlDocument += "\n";
	}
}

string XMLSchema::generateXMLDocument()
{
	cout << "XMLSchema generateXMLDocument!" << endl;

	// print out for upper class
	XMLResult::generateXMLDocument();

	// print out for this class
	cout << xmlDocument << endl;

	return xmlDocument;
}

void XMLDTD::setConditions(conditions condi)
{
//	conditions = condi;
}

conditions XMLDTD::getConditions()
{
	return condition;
}

void XMLDTD::setXMLData(vector<pair<string, string> > meta, vector<string> data)
{
	cout << "XMLDTD setXMLData!" << endl;

	// traverse for upper class
	XMLResult::setXMLData(meta, data);

	// traverse for this class
	vector<string>::iterator itr;

	int count = 0;
	for (itr = data.begin(); itr != data.end(); ++itr)
	{
		cout << ++count << " " << *itr << endl;
		xmlDocument += *itr;
		xmlDocument += "\n";
	}
}

string XMLDTD::generateXMLDocument()
{
	cout << "XMLDTD generateXMLDocument!" << endl;
	// print out for upper class
	XMLResult::generateXMLDocument();

	// print out for this class
	cout << xmlDocument << endl;

	return xmlDocument;
}

void XMLDocument::setConditions(conditions condi)
{
//	conditions = condi;
}

conditions XMLDocument::getConditions()
{
	return condition;
}

void XMLDocument::setXMLData(vector<pair<string, string> > meta, vector<string> data)
{
	cout << "XMLDocument setXMLData!" << endl;

	// traverse for upper class
	XMLResult::setXMLData(meta, data);

	// traverse for this class
	vector<string>::iterator itr;

	for (itr = data.begin(); itr != data.end(); ++itr)
	{
		xmlDocument += *itr;
		xmlDocument += "\n";
	}
}

string XMLDocument::generateXMLDocument()
{
	cout << "XMLDocument generateXMLDocument!" << endl;

	// print out for upper class
	XMLResult::generateXMLDocument();

	// print out for this class
	cout << xmlDocument << endl;

	return xmlDocument;
}


}

int main()
{
//	xmlGenerator::XMLGenerator xmlGenerator;

	xmlGenerator::XMLGenerator* baseXMLGenerator =
		new xmlGenerator::XMLSchema(
//		new xmlGenerator::XMLDTD(
		new xmlGenerator::XMLDocument(
		new xmlGenerator::BaseXMLGenerator());

	std::vector<std::pair<std::string, std::string> > meta;
	meta.push_back(std::make_pair("C1", "integer"));
	meta.push_back(std::make_pair("C2", "string"));

	std::vector<string> data;

	data.push_back("a");
	data.push_back("b");
	data.push_back("c");
	data.push_back("d");
	data.push_back("e");

	baseXMLGenerator->setXMLData(meta, data);
	//std::cout << baseXMLGenerator->generateXMLDocument() << endl;

	delete baseXMLGenerator;

//	xmlNodePtr n;
//	xmlDocPtr doc;
//	xmlChar *xmlBuf;
//	int bufSize;
//
//	doc = xmlNewDoc(BAD_CAST "1.0");
//	n = xmlNewNode(NULL, BAD_CAST "root");
//	xmlNodeSetContent(n, BAD_CAST "content");
//	xmlDocSetRootElement(doc, n);
//
//	xmlDocDumpFormatMemory(doc, &xmlBuf, &bufSize, 1);
//	cout << xmlBuf << endl;
//
//	xmlFree(xmlBuf);
//	xmlFreeDoc(doc);
//


	return 1;
}
