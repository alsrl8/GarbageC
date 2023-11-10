#ifndef GARBAGEC_OBJECT_H
#define GARBAGEC_OBJECT_H

typedef struct {
    unsigned int ref_count;
} Object;

Object *createObject();

void retainObject(Object *obj);

void releaseObject(Object *obj);

#endif //GARBAGEC_OBJECT_H
