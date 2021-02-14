#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;

int answer = 0;
struct PhoneBookEntry newEntry;
char entryName[50];
char entryNumber[12];



typedef struct PhoneBookEntry {
		char name [50];
		char number[12];
		char * notes;
	}PhoneBookEntry;

typedef struct Node {
	struct PhoneBookEntry data;
    struct Node* next;
}Node;



Node * AddSortedEntry(Node *head, PhoneBookEntry entry){
	Node *my_node;
	my_node = (Node *) malloc(sizeof(Node));

	if (my_node == NULL) {

	        abort();
	    }

	my_node->data = entry;
	my_node->next= NULL;

	if(head == NULL || strcmp(my_node->data.name, head->data.name) < 0){
		my_node->next = head;

		return my_node;

	}else{
		Node *my_node2 = head;
		while(my_node2->next != NULL &&  strcmp(my_node->data.name, my_node2->next->data.name) >= 0){
			my_node2 = my_node2->next;
		}
		my_node->next = my_node2->next;
		my_node2->next =my_node;

		return head;


	}







}

void printList(Node *node) {
  Node *current_node = node;
  while ( current_node != NULL) {
    printf("%s \n", current_node->data.name);
    printf("%s ", current_node->data.number);
    printf("%s \n", current_node->data.notes);
    current_node = current_node->next;
  }
  free(current_node);
}

void editEntry(Node *node, char* old_name, char* new_name, char* new_number, char* new_note) {
  Node *current_node = node;
  while (current_node != NULL) {
	  if(strcmp(current_node->data.name, old_name) == 0){
		  strcpy(current_node->data.name, new_name);
		  strcpy(current_node->data.number, new_number);
          current_node->data.notes = new_note;

		  printf("Edited successfully \n");
		  return;

	  }

		  current_node = current_node->next;

	  }


    printf("No such entry in phone book \n");


  }


char* dynamic_string(){
	int index = 0;


			char* myString = NULL;
			char input;

			myString = (char*)malloc(1*sizeof(char));


			while(input != '.'){
				input = getc(stdin);

				myString[index] = input;
				index++;


				myString = (char*)realloc(myString, (index + 1) *  sizeof(char));

			}

			myString[index] = '\0';


			return myString;


}

void deleteEntry(Node **head, char* name)
{

    Node* temp = *head, *prev;


    if (temp != NULL && strcmp(temp->data.name, name) == 0)

    {


        *head = temp->next;
        free(temp);
        return;
    }


    while (temp != NULL && strcmp(temp->data.name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }


    if (temp == NULL) return;


    prev->next = temp->next;

    free(temp);
}



int searchEntry(Node *node, char* search_string) {
  Node *current_node = node;
  int search_result_present =0;
  while (current_node != NULL) {
	  if((strcasestr(current_node->data.name, search_string) != NULL)||(strcasestr(current_node->data.notes, search_string) != NULL)){

		  printf("Search completed \n");
		  printf("%s \n", current_node->data.name);
		  printf("%s", current_node->data.number);
		  printf("%s \n", current_node->data.notes);

		  search_result_present++;

	  }

		  current_node = current_node->next;

	  }


    return search_result_present;


  }


void save_to_file(Node * node, char * file_name){
	FILE * file_pointer;

	file_pointer = fopen(strcat(file_name, ".txt"), "w");


	    if(file_pointer == NULL)
	    {

	        printf("Unable to create file.\n");
	        exit(EXIT_FAILURE);
	    }

	    Node *current_node = node;
	     while ( current_node != NULL) {

	    	 fputs(current_node->data.name, file_pointer);
	    	 fputs("\n", file_pointer);
	    	 fputs(current_node->data.number, file_pointer);
	    	 fputs(current_node->data.notes, file_pointer);

	    	 fputs("\n", file_pointer);

	    	 fputs("\n", file_pointer);

	    	 current_node = current_node->next;
	     }

	     fclose(file_pointer);

	     printf("File created and saved successfully. \n");


}

void load_file(char * file_name){

	char ch;
	FILE * file_pointer;

	file_pointer = fopen(strcat(file_name, ".txt"), "r");

	if(file_pointer == NULL){
		printf("Error while opening the file. \n");
		exit(EXIT_FAILURE);
	}

	while((ch = fgetc(file_pointer)) != EOF){
		printf("%c", ch);
	}

	fclose(file_pointer);


}


int main(){

	Node * head = NULL;
	int entrycount = 0;



	while (answer != 9){

		printf("1) New Entry \n");
		printf("2) List all entries \n");
		printf("3) Edit \n");
		printf("4) Delete \n");
		printf("5) Search \n");
		printf("6) Save and exit \n");
		printf("7) Load \n");

		scanf("%d", &answer);

		if(answer == 1){
			printf("Enter a name:");
			scanf("%s", entryName);
			printf("Enter a number:");
			scanf("%s", entryNumber);
			printf("Enter a note:");



			strcpy(newEntry.name, entryName);
			strcpy(newEntry.number, entryNumber);
			newEntry.notes = dynamic_string();







			head = AddSortedEntry(head, newEntry);




			entrycount++;


			printf("Entry has been successfully created. Total number of entries: %d \n", entrycount);


		}else if(answer == 2){
			printList(head);

		}else if (answer == 3){
			char newName[50];
			char * string;
			printf("Enter the name of the contact you would like to edit:");
			scanf("%s", entryName);
			printf("Enter the new name of the contact:");
			scanf("%s", newName);
			printf("Enter a new number:");
			scanf("%s", entryNumber);
			printf("Enter a new note note:");

			string = dynamic_string();


			editEntry(head, entryName, newName, entryNumber, string);



			free(string);


		}else if (answer == 4){
			char nametoDelete[50];
			printf("Enter the name of the contact you would like to delete:");
			scanf("%s", nametoDelete);
			deleteEntry(&head, nametoDelete);
			entrycount--;

			printf("Contact deleted successfully. Total Number of Entries %d \n", entrycount);

		}else if(answer == 5){
			char string_to_Search[50];
			printf("Enter the string you would like to search :");
			scanf("%s", string_to_Search);


			if(searchEntry(head, string_to_Search) == 0){
				printf("No results found  \n");
			}
		}else if(answer == 6){
			char fileName[50];
			printf("Enter the name of your file :");
			scanf("%s", fileName);

			save_to_file(head, fileName);


			free(head);

			break;
		}else if(answer == 7){
			char fileName[50];
			printf("Enter the name of your file :");
			scanf("%s", fileName);

			load_file(fileName);
		}

	}










}
