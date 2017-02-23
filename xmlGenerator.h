//#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>
#include <libxml/parser.h>
#include <vector>
#include <string>

using namespace std;

namespace xmlGenerator
{

struct conditions
{
	bool isHeader;
	bool isFooter;
};

typedef struct conditions conditions;

class XMLGenerator
{
public:
	conditions condition;
	string xmlDocument;

	virtual void setConditions(conditions condi) = 0;
	virtual conditions getConditions() = 0;

	virtual void setXMLData(const vector<pair<string, string> > &meta, const vector<string> &data) = 0;
	virtual string generateXMLDocument() = 0;
//	virtual bool verifyXML() = 0;
};

class BaseXMLGenerator : public XMLGenerator
{
	void setConditions(conditions condi);
	conditions getConditions();

	void setXMLData(const vector<pair<string, string> > &meta, const vector<string> &data);
	string generateXMLDocument();
};

class XMLResult : public XMLGenerator
{
private:
	XMLGenerator* xmlGenerator;

public:
	XMLResult(XMLGenerator* xmlGenerator)
	{
		this->xmlGenerator = xmlGenerator;
	}

	~XMLResult()
	{
		if (!xmlGenerator) delete xmlGenerator;
	}

	void setConditions(conditions condi);
	conditions getConditions();

	void setXMLData(const vector<pair<string, string> > &meta, const vector<string> &data);
	string generateXMLDocument();
};

class XMLSchema : public XMLResult
{
public:
	XMLSchema(XMLGenerator* xmlGenerator) : XMLResult(xmlGenerator) { }

	void setConditions(conditions condi);
	conditions getConditions();

	void setXMLData(const vector<pair<string, string> > &meta, const vector<string> &data);
	string generateXMLDocument();
};

class XMLDTD : public XMLResult
{
public:
	XMLDTD(XMLGenerator* xmlGenerator) : XMLResult(xmlGenerator) { }

	void setConditions(conditions condi);
	conditions getConditions();

	void setXMLData(const vector<pair<string, string> > &meta, const vector<string> &data);
	string generateXMLDocument();
};

class XMLDocument : public XMLResult
{
public:
	XMLDocument(XMLGenerator* xmlGenerator) : XMLResult(xmlGenerator) { }

	void setConditions(conditions condi);
	conditions getConditions();

	void setXMLData(const vector<pair<string, string> > &meta, const vector<string> &data);
	string generateXMLDocument();
};


//class XMLDTD : public XMLResult
//{
//	XMLDTD(XMLGenerator* xmlGenerator) : XMLResult(XMLGenerator* xmlGenerator) { }
//};
////
//class XMLDocument : public XMLResult
//{
//	XMLDocument(XMLGenerator* xmlGenerator) : XMLResult(XMLGenerator* xmlGenerator) { }
//};
//

}
