#include "main.hpp"
#include "dom.hpp"

using namespace xercesc;

int main() {
    init();
    tree();
    terminate();
}

int tree() {
    //create an XML string variable
    XMLCh tempStr[100];
    XMLString::transcode("Range", tempStr, 99);
    DOMImplementation* impl = DOMImplementationRegistry::getDOMImplementation(tempStr);
    printf("temp XML String Created\n");

    //create the root element
    XMLString::transcode("root", tempStr, 99);
    DOMDocument*   doc = impl->createDocument(0, tempStr, 0);
    DOMElement*   root = doc->getDocumentElement();
    printf("XML DOC Created\n");

    //create and append an element
    XMLString::transcode("FirstElement", tempStr, 99);
    DOMElement*   e1 = doc->createElement(tempStr);
    root->appendChild(e1);
    printf("First Element Created\n");

    //create and append an element
    XMLString::transcode("SecondElement", tempStr, 99);
    DOMElement*   e2 = doc->createElement(tempStr);
    root->appendChild(e2);
    printf("Second XML Element Created\n");

    return 0;
}

int init() {
    //initialize the xerces system
    try {
        XMLPlatformUtils::Initialize();
    } catch (const XMLException &toCatch) {
        printf("Xerces system initialization failed\n");
        return 1;
    }
    printf("Xerces system initialized\n");
    return 0;
}

int terminate() {
    //terminate the xerces system
    XMLPlatformUtils::Terminate();
    printf("Xerces system terminated\n");

    return 0;
}

