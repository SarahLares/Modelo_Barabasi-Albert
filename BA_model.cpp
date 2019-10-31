#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
#include<stdlib.h>
#include<fstream>

using namespace std;


struct nodes{
   double prob;
   vector<int> links;
};


vector <nodes> red_inicial(int k, int mo);
vector<nodes> probability(vector <nodes> B);
vector<nodes> Conection(int b, int c, vector<nodes>B);
double Pre_Att(double num,vector<nodes> B);
vector <nodes> Add_node(vector <nodes> B,int num_nodes,int k,int mo);
void BA_model(int m, int k, int mo);

int main()
{
	int m,k,mo;

    cout<<"Ingrese el numero de nodos que tendra la red: ";cin>>m;
    cout<<"Ingrese el numero de nodos que tendra la red inicial mo<m: ";cin>>mo;
    cout<<"Ingrese el numero maximo de conexiones que puede hacer un nodo nuevo: ";cin>>k;
    BA_model(m,k,mo);
 

 

   return 0;
}


vector<nodes> probability(vector <nodes> B)
{
   double Lt;
   for(int s=0;s<B.size();s++) Lt+=B[s].links.size();
   for(int s=0;s<B.size();s++) B[s].prob=B[s].links.size()/Lt;
   return B;
}


vector<nodes> Conection(int b, int c, vector<nodes>B)
{
   B[c].links.push_back(b);
   B[b].links.push_back(c);
   return B;
}



vector <nodes> red_inicial(int k, int mo)
{

   int* b;
   b=(int*)malloc (mo*sizeof(int));
   for(int i=0;i<mo;i++)b[i]=i;

   vector <nodes> B(mo);

   for(int i=0;i<mo;i++)
   {
       random_shuffle ( b,b+mo );
       for(int j=0;j<k;j++)
       {
         if(b[j]!=i)
         {
            int c=B[i].links.size();
            if(c==0)
            {
               B=Conection(b[j], i,B);
            }
            else
            {
               int cont=0;
               for(int l=0;l<c;l++) if(b[j]==B[i].links[l]) cont+=1;

               if(cont==0)
               {
                  B=Conection(b[j], i,B);
               }
            }
         }
       }
   }
   free(b);

   ofstream file1,file2;
   file1.open("BA.dat",ios::out);
   file2.open("probabilidad.dat",ios::out);
   B=probability(B);
   for(int s=0;s<B.size();s++)
   {
      file2<<s<<","<<B[s].prob<<endl;
      for(int t=0;t<B[s].links.size();t++)   file1<<s<<","<<B[s].links[t]<<endl;
   }

   file1.close();
   file2.close();
   return B;
}



double Pre_Att(double num,vector<nodes> B)
 {
    double P,Q, cont;
    for(int i=0;i<B.size();i++)
    {
      cont=0;
       Q=(B[i].prob)*100;
       P+=(B[i].prob)*100;
       if(i==0)
       {
          if(0<=num&& num<=(P))
          {

             return i;
          }
       }
       else
       {
          if((P-Q)<num && num<=P)
          {
             return i;
          }
       }

    }
    //return cont;
 }


vector <nodes> Add_node(vector <nodes> B, int num_nodes,int k, int mo)
{

   int a, p,c,d , N=mo+num_nodes;

   for(int i=mo; i<N;i++)
   {
      nodes o;
      for(int j=0;j<k;j++)
      {
         a=(rand()%101);
         p=Pre_Att(a,B);
         B.push_back(o);
         int c=B[i].links.size();
         if(c==0)
            {
               B=Conection(i,p,B);
            }
            else
            {
               int cont=0;
               for(int l=0;l<c;l++) if(p==B[i].links[l]) cont+=1;

               if(cont==0) B=Conection(i,p,B);
            }
      }
      B=probability(B);

   }
   return B;

}



void BA_model(int m, int k, int mo)
{
   srand((int)time(NULL));
   ofstream file1, file2;
   file1.open("BA_model.dat",ios::out);
   file2.open("BA_network.dat",ios::out);
   int cont;
   vector <nodes> Z;
   Z=red_inicial(k,mo);
   Z=Add_node(Z,m-mo,k,mo);
   for(int s=0;s<Z.size();s++)
   {
      for(int t=0;t<Z[s].links.size();t++)
      {
         file2<<s<<","<<Z[s].links[t]<<endl;
      }
   }
   for(int i=1;i<500;i++)
   {
      cont=0;
      for(int j=0;j<Z.size();j++) if(Z[j].links.size()==i)cont+=1;
      file1<<i<<","<<cont<<endl;
   }


   file1.close();
   file2.close();

}
