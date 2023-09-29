#ifndef FIELD
#define FIELD

    struct field_t;

    //field allocation 
    struct field_t* field_new();

    void field_ctor(struct field_t*);
    void field_dtor(struct field_t*);
    void set_field_value(struct field_t*, );

#endif