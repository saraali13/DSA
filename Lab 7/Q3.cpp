/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
#include <string>
using namespace std;

class StudentNode 
{
public:
    string name;
    int score;
    StudentNode* next;

    StudentNode(string name, int score) : name(name), score(score), next(NULL) {}
};

class StudentLinkedList 
{
private:
    StudentNode* head;

public:
    StudentLinkedList() : head(NULL) 
	{}

    void insert(string name, int score) 
	{
        StudentNode* newNode = new StudentNode(name, score);
        if (head==NULL) 
		{
            head = newNode;
        } 
		else 
		{
            StudentNode* temp = head;
            while (temp->next!=NULL) 
			{
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int getMaxScore() 
	{
        int maxScore = head->score;
        StudentNode* current = head;
        while (current!=NULL) 
		{
            if (current->score > maxScore) 
			{
                maxScore = current->score;
            }
            current = current->next;
        }
        return maxScore;
    }

    void countingSort(int exp) 
	{
        StudentNode* output = NULL;
        int count[10] = {0};

        StudentNode* current = head;
        while (current->next!=NULL) 
		{
            count[(current->score / exp) % 10]++;
            current = current->next;
        }

    
        for (int i = 1; i < 10; i++) 
		{
            count[i] += count[i - 1];
        }

        for (int i = 9; i >= 0; i--) 
		{
            while (count[i] > 0) 
			{
                StudentNode* temp = head;
                while (temp->next!=NULL) 
				{
                    temp = temp->next;
                }
                if (head!=NULL) 
				{
                    output = new StudentNode(head->name, head->score);
                    head = head->next;
                }
                count[i]--;
            }
        }

        head = output;
    }

    void radixSort() 
	{
        int maxScore = getMaxScore();
        for (int  = 1; maxScore / exp > 0; exp *= 10) 
		{
            countingSort(exp);
        }
    }

    void printStudents() 
	{
        StudentNode* current = head;
        while (current) 
		{
            cout << current->name << ": " << current->score << endl;
            current = current->next;
        }
    }
};

int main() {
    StudentLinkedList list;

    list.insert("Sara", 88);
    list.insert("Ali", 75);
    list.insert("Abbas", 90);
    list.insert("Haider", 82);
    list.insert("Sakina", 88);
    
    cout << "Original list of students:\n";
    list.printStudents();

    list.radixSort();

    cout << "\nSorted list of students by scores:\n";
    list.printStudents();

    return 0;
}
