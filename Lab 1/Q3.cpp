/*You're tasked with designing a Document class for a document editor program. The class should
handle text content, ensuring that copying a document creates a deep copy of the content to maintain
data integrity. Follow the Rule of Three to manage resource allocation and deallocation correctly.
Here are the key requirements:
(a) Create a constructor that takes initial text content and allocates memory for it.
(b) Implement a destructor to deallocate memory used for the text content.
(c) Create a copy constructor that performs a deep copy of the text content, preventing unintended
sharing.
(d) Create a copy assignment operator that ensures a deep copy of the text content, maintaining
separation between objects.
(e) Provide a sample program that showcases your Document class. Create an original document,
generate copies using both the copy constructor and copy assignment operator, modify the
original's content, and show that the copies remain unaffected*/
/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
#include <cstring>
using namespace std;

class Document
{
private:
    char* content;

public:
    Document(char* cont)
    {
        content=new char[strlen(cont)+1];
        strcpy(content,cont);
    }

    ~Document()
    {
      delete[] content;
    }

    Document(Document &Doc)
    {
      content=new char[strlen(Doc.content)+1];
      strcpy(content,Doc.content);
    }

    Document operator=(Document& Doc)
    {
       if (this != &Doc)
       {
        delete[] content;
        content=new char[strlen(Doc.content)+1];
        strcpy(content,Doc.content);
       }
       return *this;
    }

    void reset(char* cont)
    {
        delete[] content;
        content=new char[strlen(cont)+1];
        strcpy(content,cont);
    }

    void Display()
    {
        cout<<"Content in the Document:\n";
        cout<<content<<endl;
    }
};

int main()
{
    Document D1("Hi hello");
    Document D2(D1);
    Document D3("Good Bye");

    cout<<"Displaying Orignal Content\n";
    D1.Display();
    D2.Display();
    D3.Display();

    cout<<"\nAfter Using = Operator\n";
    D2=D3;
    D1.Display();
    D2.Display();
    D3.Display();

    D3.reset("Chintapak DAM DAM");
    cout<<"\nAfter Resetting the content\n";
    D1.Display();
    D2.Display();
    D3.Display();

    return 0;
}
