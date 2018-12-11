#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
#include "minisat/core/SolverTypes.h"
#include "minisat/core/Solver.h"
using namespace std;

//Input Parsing
string input_parse(int vertices, string s)
{
    string delimiter1 = "}";
    string delimiter2 = "<";
    string delimiter3 = ">";
    string comma = ",";
    size_t pos = 0;
    size_t pos2 = 0;
    string token;
    int vint;

    if (s.find("E") == 0) {
        s.erase(0,3);
        pos2 = s.find(delimiter1);
        s.erase(pos2,1);
    }
    string scheck = s;
    while ((pos = s.find(delimiter2)) != string::npos) {
                s.erase(pos,1);
                pos2 = s.find(delimiter3);
                s.erase(pos2,1);
            }

    while ((pos = s.find(comma)) != string::npos) {
                token = s.substr(0,pos);
                vint = atoi(token.c_str());
                if(vint >= vertices)
                    {
                    scheck = " ";
                    return scheck;
                    }
                else
                    {
                    s.erase(0,token.length()+1);
                    }
                }
        vint = atoi(s.c_str());
        if(vint >= vertices)
                        {
                        scheck = " ";
                        return scheck;
                        }


    return scheck;

}



                ///Function call
void vertex_coversat(int Vertices1,vector<int> ijdet1)
{

 std::vector<int> answer;

 int k,low,high;
 low = 0;
 high = Vertices1;
 int n = Vertices1;
 while(low<=high)
 {
    k = int (low + high )/ 2;
     std::vector<std::vector<Minisat::Lit> > x(n);

        Minisat::Solver solver;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < k; j++)
            {
                Minisat::Lit li = Minisat::mkLit(solver.newVar());
                x[i].push_back(li);
            }
        }

     //At least one vertice is the ith vertex in the vertex cover
        for(int i = 0; i < k; i++)
        {
            Minisat::vec<Minisat::Lit> temp;
            for(int j = 0; j < n; j++)
            {
                temp.push(x[j][i]);
            }
             solver.addClause( temp );
             temp.clear();
        }

       // No one vertex can  appear twice in vertex cover
        for(int i=0;i< n;i++)
        {
            for(int j=0;j<k-1;j++)
            {
                for (int ab=j+1;ab<k;ab++)
                {
                    solver.addClause(~x[i][j],~x[i][ab]);
                }

            }
        }
 
        //No more than one vertex in two pos in v.cover
        for(int i=0;i< k;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                for (int ab=j+1;ab<n;ab++)
                {
                    solver.addClause(~x[j][i],~x[ab][i]);
                }

            }
        }
        //Every edge is incident on at least one vertex in vertex cover
        int len_size = ijdet1.size();
            for(int j=0;j<len_size;j+=2)
            {       int q = ijdet1[j];
                    int rs = ijdet1[j+1];
                    
                Minisat::vec<Minisat::Lit> temp1;
                 for(int i=0;i< k;i++)
                 {
                   temp1.push(x[q][i]);
                   temp1.push(x[rs][i]);
                    
                 }
                 solver.addClause(temp1);
                 temp1.clear();
            }

          // Check for solution and retrieve model if found
        // Check for solution and retrieve model if found

    auto sat = solver.solve();
     if (sat) {
                        high = k-1;
                       answer.clear();
                       for(int i = 0; i < n; i++)
                        {
                            for(int j = 0; j < k; j++)
                            {
                              Minisat::lbool tf=solver.modelValue(x[i][j]);
                                if(tf==Minisat::l_True)
                            {   

                                answer.push_back(i);
                            }

                
     }}}
     else
     {
                    low = k+1;
        }


 }

            int xl = answer.size();
            for (int i = 0;i<xl;i++)
            {
                std::cout<<answer[i]<<" ";
            }
            std::cout<<std::endl; 
            answer.clear();
}
//Main Program
int main(int argc, char** argv)
{
    using Minisat::mkLit;
    using Minisat::lbool;

    string v;
    string s;
    string scheck;

    //Parsing Operator Variables
    string vdelimiter = "V ";
    size_t vpos = 0;
    string spath;
    string delimiter2 = "<";
    string delimiter3 = ">";
    string comma = ",";
    size_t pos = 0;
    size_t pos2 = 0;
    size_t spos = 0;
    string token;
    int sr,des;

    vector<int> path; //Shortest Path Array
    vector<int> ijdet;
    
    int vertices;  //Integer Values
    // Prepare Adjacency Matrix


    while(std::getline(cin,v))
    {
        //EOF
        if(v == "") continue;

        //Pick Vertice Number
        if (v.find("V ") == 0)
        {
                    v.erase(vpos,2);
                    vertices = atoi(v.c_str());
                    path.clear();
                    scheck.clear();

        }
            //Edge Input
        if (v.find("E ") == 0)
        {
            
            s = v;
            scheck = input_parse(vertices,s);
            if (scheck!= " ")
            {
                while ((pos = scheck.find(delimiter2)) != string::npos)

                {
                        pos2 = scheck.find(delimiter3);
                        token = scheck.substr(pos+1, pos2-1);
                        spos = token.find(comma);
                        sr = atoi(token.substr(0,spos).c_str());
                        //cout << sr;
                        ijdet.push_back(sr);
                        token.erase(0,spos+1);
                        des = atoi(token.c_str());
                        //cout << des;
                        ijdet.push_back(des);
                        scheck.erase(pos, pos2+2);
                    }

                    vertex_coversat(vertices,ijdet);
                    ijdet.clear();

            }
            else cerr << "Error: Invalid Entry"<< endl;

        }


    }
    return 0;
}


