#include <iostream>
#include <string>

template < class Key,class Information>
class Database;


template < class Key, class Information>
class DataRecord{

     public:

     DataRecord(Key key, Information information)
                :_key(key),_information(information)
                {}
     Information getInformation() const
     {
        return _information;
     }
     Key getKey() const
     {
        return _key;
     }

     bool isMatch(const DataRecord& record) const
     {
         return record._key == _key;
     }

     private:
     DataRecord(){}


     Key _key;
     Information _information;

     friend class Database<Key,Information>;
};


template < class Key, class Information>
class Database{

   public:
     Database(int databaseSize)
                :currentSize(0),allocateSize(databaseSize),storage(new DataRecord<Key,Information>[databaseSize])
            {}

    void store(const Key key,const Information information)
    {
            if(currentSize >= allocateSize)
                {
                    std::cerr << "\ndatabase has full!!!\n";
                    return;
              }

            storage[currentSize++] = DataRecord<Key,Information>(key,information);
    }

    bool  retrieve(const Key k,Information& information) const

    {
            for(int i =0; i < currentSize; ++i)
            {
                  if(storage[i]._key == k)
                    {
                    information  = storage[i]._information;
                     std::cout << "\n" << information << std::endl;
                    }
                  return true;
            }

            return false;

    }

    ~Database()
    {
        delete[] storage;
    }
   private:

    DataRecord <Key, Information>* storage;
    int currentSize;
    int allocateSize;
};


int main(int argc,char* argv[])
{
  DataRecord<int,char*> stu1(22,"huqingyuan");
  DataRecord<int,char*> stu2(1,"zhangyue");

  Database<int,std::string> database(10);

  database.store(22,"jerry");
  database.store(1,"fox");

  std::string str;
  database.retrieve(22,str);

  std::cout << std::endl << str;



}
