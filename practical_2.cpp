//consideer the telephone book database of N clients. Make use of a HASH TABLE
//implementation to quickly loo up client's telephone number. make use of two 
//collision andling techniques with replacement and compare them using number of 
//comparisions required to find a set of telephone numbers.
/*
#include<iostream>
using namespace std;

struct node
{
    int value;
    node*next;
}*HashTable[10];

class hashing
{
    public:
        hashing()
        {
            for(int i=0;i<10;i++)
            {
                HashTable[i]=NULL;
            }
        }

    int HashFunction(int value)
    {
        return (value%10);
    }

    node* creat_node(int x)
    {
        node* temp=new node;
        temp->next=NULL;
        temp->value=x;
        return temp;
    }

    void display()
    {
        for(int i=0;i<10;i++)
        {
            node * temp=new node;
            temp=HashTable[i];
            cout<<"a["<<i<<"] : ";
            while(temp !=NULL)
            {
                cout<<" ->"<<temp->value;
                temp=temp->next;
            }
            cout<<"\n";
        }
    }

    int searchElement(int value)
    {
        bool flag=false;
        int hash_val = HashFunction(value);
        node * entry = HashTable[hash_val];
        cout<<"\nElement found at : ";
        while(entry!=NULL)
        {
            if(entry->value==value)
            {
                cout<<hash_val<<" : "<<entry->value<<endl;
                flag=true;
            }
            entry=entry->next;
        }
        if(!flag) return -1;
        else return 1;
    }

    void deleteElement(int value)
    {
        int hash_val = HashFunction(value);
        node* entry = HashTable[hash_val];
        if(entry == NULL)
        {
            cout<<"No Element found ";
            return;
        }
        if(entry->value==value)
        {
            HashTable[hash_val]=entry->next;
            return;
        }
        while((entry->next)->value !=value)
        {
            entry=entry->next;
        }
        entry->next=(entry->next)->next;
    }

    void insertElement(int value)
    {
        int hash_val = HashFunction(value);
        node* temp=new node;
        node* head=new node;
        head = creat_node(value);
        temp=HashTable[hash_val];
        if (temp == NULL)
        {
            HashTable[hash_val] = head;
        }
        else
            while(temp->next != NULL)
            {
                temp =temp->next;
            }
        temp->next=head;
    }
    
};

int main()
{
    int ch;
    int data,search,del;
    hashing h;
    do
    {
        cout<<"\nTelephone : \n1.Insert \n2.Display \n3.Search \n 4.Delete \n 5.Exit";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\nEnter phone number to be inserted : ";
                    cin>>data;
                    h.insertElement(data);
                    break;
            case 2: h.display();
                    break;
            case 3: cout<<"\nEnter the no to be searched : ";
                    cin>>search;
                    if(h.searchElement(search)==-1)
                    {
                        cout<<"No element found at key ";
                        continue;
                    }
                    break;
            case 4: cout<<"\nEnter the phno. to be deleted : ";
                    cin>>del;
                    h.deleteElement(del);
                    cout<<"Phno. Deleted"<<endl;
        }
    } while (ch!=5);

    return 0;
}
*/

#include<iostream>
using namespace std;

struct node
{
    int value;
    node*next;
}*HashTable[10];

class hashing
{
    public:
    hashing()
    {
        for(int i=0;i<10;i++)
        {
            HashTable[i]=NULL;
        }
    }

    int HashFunction(int value)
    {
        return(value%10);  
    }

    node*creat_node(int x)
    {
        node *temp = new node;
        temp->next=NULL;
        temp->value=x;
        return temp;
    }

    void insert(int data)
    {
        int hashvalue=HashFunction(data);
        node*head=new node;
        node*temp=new node;
        head=creat_node(data);
        temp=HashTable[hashvalue];
        if(temp==NULL)
        {
            HashTable[hashvalue]=head;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=head;
        }
    }

    void display()
    {
        for(int i=0;i<10;i++)
        {
            node*temp=new node;
            temp=HashTable[i];
            cout<<"a["<<i<<"]  :";
            while(temp !=NULL)
            {
                cout<<" ->"<<temp->value;
                temp=temp->next;
            }
            cout<<"\n";
        }
    }

    void search(int search)
    {

    }


};

int main()
{
    int data,search,ch;
    hashing h;
    do
    {
        cout<<"\n****main manu****\n\n1.insert element.\n2.display hash table.\n3.search element.\n4.Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch (ch)
        {
            case 1: cout<<"Enter the number : ";
                    cin>>data;
                    h.insert(data);
                    break;
            
            case 2: h.display();
                    break;
            
            case 3: cout<<"Enter the number : ";
                    cin>>search;
                    h.search(search);
                    break;
        }
    } while (ch!=4);
    return 0;
    
}