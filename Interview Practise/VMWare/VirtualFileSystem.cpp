#include <iostream>
#include <string>
#include <list>

using namespace std;

class Entity
{
private:
    void path(Entity* ent, string& str)
    {
        if(!ent)
            return;
        path(ent->parent, str);
        str+="/"+ent->name;
    }
protected:
    string name{};
    Entity* parent{};
public:
    Entity(string_view sv)
        : name{sv}
    {}
    string getPath()
    {
        string ans{};
        path(this, ans);
        return ans;
    }
    void setParent(Entity* ent) { parent = ent;}
};

class File: public Entity
{
public:
    File(string_view sv)
        : Entity(sv)
    {}
};

class Directory: public Entity
{
private:
    list<Entity*> entities;
public:
    Directory(string_view sv)
        : Entity(sv)
    {}
    void addEntity(Entity* entity)
    {
        entities.emplace_back(entity);
        entity->setParent(this);
    }
};

class FileSystem
{
public:
    void deleteEntity(Entity* ent)
    {

    }
};

int main()
{
    Directory root("root");
    File *f1 = new File("file1.txt");
    Directory *dir = new Directory("dir1");

    root.addEntity(f1);
    root.addEntity(dir);

    File *f2 = new File("file2.txt");
    dir->addEntity(f2);
    dir->addEntity(new Directory("dir2"));

    cout<<"Path : "<<f1->getPath()<<"\n";
    cout<<"Path : "<<f2->getPath()<<"\n";

    delete f1;
    delete f2;
    delete dir;

    return 0;
}