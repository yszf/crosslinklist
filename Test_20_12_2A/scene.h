#ifndef __SCENE_H__
#define __SCENE_H__
#include <map>
#include <list>
#include <iostream>

#define DISTANCE 5

using namespace std;

class Scene {
public:
    Scene();
    ~Scene();

    void Add(int id, int x, int y, int distance = DISTANCE);
    void Move(int id, int x, int y);
    void Leave(int id);
	void PrintList();
	void PrintAOI(int id);

private:
    struct Object {
        int x;
        int y;
        int id;
        int radius;

        list<Object *>::iterator x_pos;
        list<Object *>::iterator y_pos;

        Object(int _id, int _x, int _y, int _radius) 
            : id(_id)
            , x(_x)
            , y(_y)
            , radius(_radius) {
        }
    };

private:
    typedef map<int, Object *> ObjMap;
    typedef list<Object *> ObjList;

    void Update(Object *object);
    void GetRangeSet(Object *object, ObjMap *set);
    void UpdateObjectPosition(Object *object, int x, int y);

private:
    ObjList obj_x_list_;
    ObjList obj_y_list_;
    ObjMap  obj_set_;

    ObjMap  move_set_;
    ObjMap  enter_set_;
    ObjMap  leave_set_;

	ObjMap  aoi_set_;
};

#endif  // __SCENE_H__
