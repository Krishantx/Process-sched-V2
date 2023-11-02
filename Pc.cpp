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
    void pointeraddr(int* a, int* b)
    {
        rp = a;
        pp = b;
    }

    void resource_input()
    {
        //Inputs the number of resources and their respective instances;
        cout<<"How many resources?"<<endl;
        cin>>nr;
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
        cout<<"Enter the number of processes: "<<endl;
        cin>>np;
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
            for (int j=0; i<temp; i++)
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
        
    }

    int nores()
    {
        return nr;
    }
    int nopro()
    {
        return np;
    }
};

void printarr(int* ptr)
{
    
}

int main()
{
    PC obj;
    obj.resource_input();
    int r[obj.nores()];
    int p[obj.nores()][obj.nopro()];
    for (int i=0; i<obj.nores(); i++)
    {
        for (int j=0; j<obj.nopro(); j++)
        {
            p[i][j]=0;
        }
    }
    obj.pointeraddr(r, &p[0][0]);
    printarr(&p[0][0]);

}

