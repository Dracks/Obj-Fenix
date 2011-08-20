#ifndef OBJETO_H
#define OBJETO_H


class Objeto
{
protected:
    long ref_count;
    long size;
    clase *ref_clase;
    Objeto *super_objeto;
    clist variables;
public:
    Objeto();
    virtual ~Objeto();
    void incCount() {ref_count++};
    void decCount() {ref_count--};
    long getNumReferencias() {return ref_count};
};

#endif // OBJETO_H
