vector<int> vec;
make_heap(vec.begin(),vec.end(),greater<int>());
        for(int i=k;i<n;++i){
            int x;cin>>x;
            if(*vec.begin()<x){
                pop_heap(vec.begin(),vec.end(),greater<int>());{
                    cout<<"before pop "<<*(vec.end()-1)<<endl;
                    vec.pop_back();
                    cout<<"after pop "<<*(vec.end()-1)<<endl;
                }
                cout<<"before push "<<*(vec.end()-1)<<endl;
                vec.push_back(x); push_heap(vec.begin(),vec.end(),greater<int>());
                cout<<"after push "<<*(vec.end()-1)<<endl;
            }
        }
        sort_heap(vec.begin(),vec.end(),greater<int>());
        cout<<*(vec.end()-1)<<endl;