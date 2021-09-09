#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

double *read_arr(string filename, int *size){
    int count=0;
    double j;
    // read file 
    ifstream  myfile;
    myfile.open(filename);
    if (myfile.is_open())
        while ( myfile>>j )
            count++;
    else  //Error message
        cerr << "Can't find input file " << filename << endl;
    myfile.close();
    //read for a second time and save the numbers in an array
    myfile.open(filename);
    if(count >0){
        *size=count;
        double *arr = new double[count];
        for(int i=0;i<count;i++)
            myfile>>arr[i];
        myfile.close(); // CLose input file 
        return arr;
    }
    myfile.close(); // CLose input file
    return NULL;
}

void printarray(double *arr,int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<",";
    cout<<"\n";
}
double max_distance(string filename){
    int size;
    double *array=read_arr(filename,&size);
    double max=0;
    // go over the numbers and check whats the result of the subtraction 
    // and everytime compare to max if its bigger then its the new max 
    for(int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            if(array[i]-array[j]>max)
                max=array[i]-array[j];
        }
    }
    return max;
}

string longest_word(string file_name){
    ifstream myfile;
    myfile.open(file_name);
    int max=0;
    char word[20],temp[20];
    if (myfile.is_open()){
        while (myfile>>word)
            if(strlen(word)>max)
            {
                max=strlen(word);
                // keep the current word in a temp var so we return it later
                strcpy(temp,word);
            }
    }
    else  //Error message
        cerr << "Can't find input file " << file_name << endl;
    myfile.close();
    return temp;
}
int main() {

    cout<<"Please choose what youd like to do by inserting a number"<<"\n";
    cout<< "Menu:"<<"\n";
    cout<< "1.	Exit"<<"\n";
    cout<< "2.	Read and print array of numbers from file."<<"\n";
    cout<< "3.	Display a maximum distance of numbers from file."<<"\n";
    cout<< "4.	Display the longest word in  file. "<<"\n";
    int choice;
    cin >> choice;
    while(choice!=1){

        if(choice==2){
            int size;
            string name;
            cout<< "insert the name of the file:"<<"\n";
            cin >> name;
            double *array=read_arr(name,&size);
            printarray(array,size);
        }
        else if(choice==3){
            string name;        
            cout<< "insert the name of the file:"<<"\n";
            cin >> name;
            cout<<max_distance(name)<<"\n";
        }
        else if(choice==4){
            string name;        
            cout<< "insert the name of the file:"<<"\n";
            cin >> name;
            cout<<longest_word(name)<<"\n";
        }
        else 
            cout << "Wrong input"<<"\n";
        cout<< "Menu:"<<"\n";
        cout<< "1.	Exit"<<"\n";
        cout<< "2.	Read and print array of numbers from file."<<"\n";
        cout<< "3.	Display a maximum distance of numbers from file."<<"\n";
        cout<< "4.	Display the longest word in  file. "<<"\n";
        cin >> choice;

    }

    return 0;
}