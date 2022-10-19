
#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	node *next;
} Node;

class linkedList {
	private:
		node *head;// head pointer
		node *tail;// tail pointer
		
		
	public:
		
		/*default constructor that creates 
		 an empty linked list */
		linkedList(){
			head = NULL;
			tail = NULL;
		}
		
		linkedList(const linkedList& List2) {
			head = List2.head;
			tail = List2.tail;
		}
		
//		~linkedList() {};
		
		void insert_node_at_front (int number) {
			node *temp = new node();
			temp->data = number;
			temp->next = head;
			head = temp;
		}
		
		void insert_node_at_back (int number) {
			node *temp = new node();
			temp->data = number;
			temp->next = NULL;
			
			if (head == NULL) {
				head = temp;
				tail = temp;
				temp = NULL;
			}else {
				tail->next = temp;
				tail = temp;
			}
		}
		
		void display(){
		    node *temp=new node;
		    temp = head;
		    if (head == NULL) { 
		       cout<<"Error: The linked list is empty, add a number to the list!\n";       
		       return;  
		    }else {
			    cout<<"Below are the elements of the linked list currently\n";
			    while(temp!=NULL){
			      cout<<temp->data<<"\t";
			      temp=temp->next;
			    }		    	
			}

	  	}
	  	
		  /* Constructor that generates a linked list of random integers*/
		linkedList(int listSize) {
			int i=0;
			while (i < listSize) {
				insert_node_at_back (rand());
				i++;
			}
			display();
		}
		
		void delete_given_number(int number){
		  struct node *previous, *current;
		  while(head != NULL && head ->data == number){
		    previous = head;
		    head = head ->next;
		    delete(previous);
		    cout<<"The number has been deleted successfully!\n";
		    return;
			  }
			  previous = NULL;
			  current = head;
			  while(current != NULL){
		    if(current ->data == number){
			if(previous !=NULL)
			    previous ->next = current ->next;
			delete(current);
			cout<<"The number has been deleted successfully!\n";
			return;
		    }
		    previous = current;
		    current = current->next;
		  }

		}

		void reverse_list() {
		    if (head == NULL) return;
			
		    node *temp = new node;
		    node *prev = new node;
		    node *current = new node;
		    
		    temp = NULL;
		    prev = NULL;
		    current = head;
		    while(current != NULL) {
		        temp = current->next;
		        current->next = prev;
		        prev = current;
		        current = temp;
		    }
		    head = prev;
		}
		
		void removeDuplicate() {  
		    node *current = new node;
		    node *index = new node;
		    node *temp = new node;
		   current = head,  index = NULL, temp = NULL;  
		      
		    if(head == NULL) {  
		        return;  
		    }  
		    else {  
		        while(current != NULL){    
		            temp = current;   
		            index = current->next;  
		              
		            while(index != NULL) {    
		                if(current->data == index->data) {   
		                    temp->next = index->next;  
		                }  
		                else {  
		                    temp = index;  
		                }  
		                index = index->next;  
		            }  
		            current = current->next;  
		        } 
				display();         
		    }  
		}  

		void search(){  
		    node *ptr = new node;  
		    int item,i=0,flag;  
		    ptr = head;   
		    if(ptr == NULL){  
		    	cout<<"The list is empty! Enter an item before searching.\n"; 
		    } else {   
		    	cout<<"Enter item which you want to search?\n";
		        cin>>item;   
		          
		        while (ptr!=NULL){  
		            if(ptr->data == item){  
		            	cout<<"Item found at node of location "<<(i+1)<<endl;
		                  
		                flag=0;
						break;  
		            }else {  
		                flag=1;  
		            }  
		            i++;  
		            ptr = ptr -> next;  
		        }  
		        if(flag==1){  
		        	cout<<"Item not found!\n";
		              
		        }  
		    }     
		          
		}
		
		
	
};

int main() {
	int size_of_list, choice, insertedNum;

	
	cout<<"Welcome!!  Enter the number of integers to be generated.\n";
	cin>>size_of_list;

	linkedList List(size_of_list);
        cout<<"\n\n---------------------------------";
        cout<<endl<<"Choose an operations on your linked list"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at the front."<<endl;
        cout<<"2.Insert node at the end."<<endl;
        cout<<"3.Display Linked List"<<endl;
        cout<<"4.Search Element"<<endl;
        cout<<"5.Reverse Linked List "<<endl;
	cout<<"6.Remove duplicates from the list."<<endl;
	cout<<"7.Delete a node with a given number"<<endl;
        cout<<"8.Exit "<<endl;
			
    while (1){
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the number to insert at the front:"<<endl;
	    cin>>insertedNum;
            List.insert_node_at_front (insertedNum);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the number to insert at the end"<<endl;
            cin>>insertedNum;
            List.insert_node_at_back (insertedNum);
            cout<<endl;
            break;
        case 3:
            List.display();
            cout<<endl;
            break;
        case 4:
            List.search();
            cout<<endl;
            break;
        case 5:
            List.reverse_list();
            cout<<endl;
            break;
        case 6:
            cout<<"Removing duplicates....."<<endl;
            List.removeDuplicate();
            cout<<endl;
            break;
        case 7:
            cout<<"\nEnter a number you want to delete: "<<endl;
            cin>>insertedNum;
            List.delete_given_number(insertedNum);
            break;            
        case 8:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
	
}
