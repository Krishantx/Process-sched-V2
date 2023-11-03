#include <iostream>
using namespace std;
class PC
{
private:
    int nr;     //number of resources
    int ans;    //just to take ans inputs
    int* rp;    //a pointer to array r;
    int* pp;    //a pointer to array p;
    int np;     //number of processes
    
public:

    void answer() { 
    int work[nr];        // Available resources
    bool finish[np];     // Track finished processes
    int safeSequence[np]; // Safe execution sequence

    // Initialize work[] with the available resources (rp[])
    for (int i = 0; i < nr; i++) {
        work[i] = rp[i];
    }

    // Initialize finish[] as false for all processes
    for (int i = 0; i < np; i++) {
        finish[i] = false;
    }

    int count = 0; // Count of executed processes

    while (count < np) {
        bool found = false;

        for (int i = 0; i < np; i++) {
            if (!finish[i]) {
                bool canExecute = true;

                for (int j = 0; j < nr; j++) {
                    if (pp[i * nr + j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute) {
                    // Execute process i
                    safeSequence[count] = i;
                    count++;

                    // Release resources held by process i
                    for (int j = 0; j < nr; j++) {
                        work[j] += pp[i * nr + j];
                    }

                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            // No process can execute, indicating a deadlock
            cout << "Deadlock detected. No safe sequence exists." << endl;
            return;
        }
    }

    // If all processes finish, a safe sequence exists
    cout << "Safe Execution Sequence:" << endl;
    for (int i = 0; i < np; i++) {
        cout << "P" << safeSequence[i] + 1 << " -> ";
    }
    cout << "All processes have executed safely." << endl;


    }

    void pointeraddr1(int* a)
    {
        rp = a;
    }

    void pointeraddr2(int* a)
    {
        pp = a;
    }

    void resource_input()
    {
        //Inputs the number of resources and their respective instances;
        cout<<"How many resources?"<<endl;
        cin>>nr;
         cout<<"Enter the number of processes: "<<endl;
        cin>>np;
        
    }

    void instance_allocation()
    {
        for (int i=0; i<nr; i++)
        {
            cout<<"Number of instances in R"<<i+1<<endl;
            cin>>*(rp+i);
        }
    }

    void processes()
    {
       
        for (int i=0; i<np; i++)
        {
            int temp;
            cout<<"How many resources allocated to P"<<i+1<<endl;
            cin>>temp;
            cout<<"Which resources:"<<endl;
            for(int j=0; j<temp; j++)
            {
                int temp2;
                cout<<"R";
                cin>>temp2;
                down(temp2-1);
            }

            cout<<"How many resources does P"<<i+1<<" request:"<<endl;
            cin>>temp;
            cout<<"Which resources: "<<endl;
            for (int j=0; j<temp; j++)
            {
                int temp2;
                cout<<"R";
                cin>>temp2;
                up(temp2-1, i);
            }
        }

    }

    void down(int rno)
    {
        *(rp+rno)=*(rp+rno)-1;
    }

    void up(int pno, int i)
    {
        *(pp+(i*nr)+pno)=*(pp+(i*nr)+pno)+1;
    }

    int nores()
    {
        return nr;
    }
    int nopro()
    {
        return np;
    }

    void yn_instance()
    {
        cout<<"Do you want to allocate instances? (default instance set to 1)"<<endl;
        cin>>ans;
        if (ans == 1)
        {
            instance_allocation();
        }
        else
        {
            for(int i=0; i<nr; i++)
            {
                *(rp+i) = 1;
            }
        }
    }


};

void printarr(int* ptr, int nr, int np)
{
    cout<<endl;
    for (int i=0; i<nr; i++)
    {
        cout<<"\tR"<<i+1;
    }
    cout<<endl;
        for (int j=0; j<np; j++)
        {
            cout<<"P"<<j+1<<"\t";
            for (int k=0; k<nr; k++)
            {
                cout<<*(ptr+(j*nr)+k)<<"\t";
            }
            cout<<endl;
        }
    }

int main()
{
    PC obj;
    obj.resource_input();
    cout<<obj.nores()<<endl;
    int r[obj.nores()];
    
    obj.pointeraddr1(r);
    obj.yn_instance();


    for (int i=0; i<obj.nores(); i++)
        {
            cout<<r[i]<<"\t";
        }
    cout<<endl;
    int p[obj.nopro()][obj.nores()];
     for (int i=0; i<obj.nopro(); i++)
    {
        for (int j=0; j<obj.nores(); j++)
        {
            p[i][j]=0;
        }
    }
    obj.pointeraddr2(&p[0][0]);

    obj.processes();
    for (int i=0; i<obj.nores(); i++)
    {
        cout<<r[i]<<"\t";
    }
    printarr(&p[0][0], obj.nores(), obj.nopro());
    obj.answer();

}

