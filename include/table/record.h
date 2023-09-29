#ifndef RECORD
#define RECORD

    struct record_t;

    //reord allocation 
    struct record_t* record_new();

    void reord_ctor(struct reord_t*);
    void reord_dtor(struct reord_t*);
    
#endif