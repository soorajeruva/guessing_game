#include"support.h"
#include<limits>

bool File::is_empty(ifstream &file)
{
    return file.peek()==ifstream::traits_type::eof();
}

void File::read_file()
{
    ifstream file;
    string line_data;
    line.clear();
    file.open(file_name,ios::app);
    if (file.is_open())
    {
        if (is_empty(file))
        {
            New=true;
        }
        else
        {
            New=false;
            while(file>>line_data)
            {
                line.push_back(line_data);
            }
        }
    }
    else
    {
        cout<<"UNABLE TO OPEN FILE FOR READING !\n";
    }
    file.close();
    return;
}

vector<string> File::get()
{   
    read_file();
    return line;
}
    
void File::write_file(tuple<string,int>&data)
{
    read_file();
    ofstream file;
    bool done=false;
    file.open(file_name);
    if (file.is_open())
    {
        if (New)
        {
            file<<"NAME,SCORE\n";
            file<<std::get<0>(data)<<","<<std::get<1>(data)<<"\n";
        }
        else
        {
            file<<"NAME,SCORE\n";
            vector<string>split_data;
            auto current_score=std::get<1>(data);

            for (int i=1;i<=line.size()-1;i++)
            {   
                string line_data=line[i];
                split(split_data,line_data,boost::is_any_of(","));

                if(!done){
                    int previous_score=std::stoi(split_data[1]);

                    if (current_score<previous_score)
                    {
                        file<<std::get<0>(data)<<","<<current_score<<"\n";
                        done=true;
                    }
                }
                file<<line_data<<"\n";
            }
            if (!done)
            {
                file<<std::get<0>(data)<<","<<current_score<<"\n";
            }
        }
    }
    else
    {
        cout<<"UNABLE TO OPEN FILE FOR WRITING !\n";
    }
    file.close();
    return;
}