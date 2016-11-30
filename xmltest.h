//#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>

namespace xmlGenerator
{

class XMLGenerator
{
	struct conditions
	{
		bool isHeader;
		bool isFooter;
	};

	typedef struct conditions conditions;

	void setConditions(conditions condi);
	conditions getConditions();
};

}
