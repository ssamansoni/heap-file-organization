#include <bits/stdc++.h>

using namespace std;

class page{
    public:
        vector<long long int> s_index;
        vector<long long int> p_key;
        long long int st_address;
        long long int size_left;
        page * prev_pg;
        page * next_pg;
};

int main(){
    page * first_pg=nullptr;
    long long int pg_count=0;
    long long int pg_size;
    cin >> pg_size;
    long long int x;
    long long int y;
    long long int pg_num;
    long long int j;
    long long int val_s;
    long long int val;
    x=2;
    while(x==1 || x==2 || x==3){
        cin >> x;
        if(x==1){
            cin >> val_s;
            cin >> val;
            if(pg_count==0){
                page * pg_var = new page;
                pg_count=1;
                first_pg=pg_var;
                pg_var->st_address=0;
                pg_var->prev_pg=nullptr;
                pg_var->next_pg=nullptr;
                pg_var->size_left=pg_size-16;
                if(val_s + 4 <= pg_var->size_left){
                    (pg_var->s_index).push_back(pg_var->st_address);
                    (pg_var->p_key).push_back(val);
                    pg_var->st_address+=val_s;
                    pg_var->size_left-=val_s;
                    pg_var->size_left-=4;
                }
                else{
                    cout << "This Record can't be inserted in any of the pages.";
                    break;
                }
            }
            else{
                page * pg_var = first_pg;
                page * pg_var2 = first_pg;
                while(val_s + 4 > pg_var->size_left){
                    pg_var2=pg_var;
                    pg_var=pg_var->next_pg;
                    if(pg_var==nullptr){
                        break;
                    }
                }
                if(pg_var==nullptr){
                    page * pg_var3=new page;
                    pg_count++;
                    pg_var2->next_pg=pg_var3;
                    pg_var3->prev_pg=pg_var2;
                    pg_var3->next_pg=nullptr;
                    pg_var3->st_address=0;
                    pg_var3->size_left=pg_size-16;
                    if(val_s + 4 <= pg_var3->size_left){
                        (pg_var3->s_index).push_back(pg_var3->st_address);
                        (pg_var3->p_key).push_back(val);
                        pg_var3->st_address+=val_s;
                        pg_var3->size_left-=val_s;
                        pg_var3->size_left-=4;
                    }
                    else{
                        cout << "This Record can't be inserted in any of the pages.";
                        break;
                    }
                }
                else{
                    (pg_var->s_index).push_back(pg_var->st_address);
                    (pg_var->p_key).push_back(val);
                    pg_var->st_address+=val_s;
                    pg_var->size_left-=val_s;
                    pg_var->size_left-=4;
                }
            }
        }
        if(x==2){
            cout << pg_count << " ";
            if(pg_count != 0){
                page * pg_var=first_pg;
                cout << (pg_var->p_key).size() << " ";
                while(pg_var->next_pg != nullptr){
                    pg_var=pg_var->next_pg;
                    cout << (pg_var->p_key).size() << " ";
                }
            }
            cout << endl;
        }
        if(x==3){
            cin >> val;
            y=0;
            page * pg_var=first_pg;
            pg_num=0;
            while(pg_num < pg_count){
                for(j=0;j<(pg_var->p_key).size();j++){
                    if((pg_var->p_key)[j]==val){
                        y=1;
                        break;
                    }
                }
                if(y==1){
                    break;
                }
                else{
                    pg_num++;
                    pg_var=pg_var->next_pg;
                }
            }
            if(y==1){
                cout << pg_num << " " << j << endl;
            }
            else{
                cout << "-1 -1" << endl;
            }
        }
    }
    return 0;
}