#include <stdlib.h>

#include "object.h"


Object *createObject() {
    Object *obj = (Object *) malloc(sizeof(Object));
    if (obj) {
        obj -> ref_count = 1;
    }
    return obj;
}

void retainObject(Object *obj) {
    if (obj) {
        obj->ref_count++;
    }
}

void releaseObject(Object * obj) {
    if (obj && --obj->ref_count == 0) {
        free(obj);
    }
}