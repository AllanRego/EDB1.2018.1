//
//  TestSequence.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include <iostream>
#include <string>
#include <cassert>
#include "Sequence.h"

using namespace std;

void printSequence(Sequence *sequence)
{
    for(int i = 0; i < sequence->getQuantity(); i++)
    {
        cout << i << " " << sequence->get(i)->getValue() << endl;
    }
}

void testInsert()
{
    Sequence *sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    string str = "teste";
    
    for(int i = 1; i <= 10; i++)
    {
        int qtBefore = sequence->getQuantity();
        string inserted = str.append(to_string(i));
        
        sequence->insert(i, new Node(inserted));
        
        for(int j = 1; j <= i; j++)
        {
            assert( sequence->get(j)->getValue() != inserted );
        }
        
        // Certifique-se que foi incrementada a quantidade
        assert( sequence->getQuantity() == qtBefore+1);
        
        // Certifique-se que o i-esimo elemento é o que foi inserido
        assert( sequence->get(i)->getValue() == inserted );
    }
    
    delete sequence;
    
    cout << "TestInsert OK" << endl;
}

void testRemove()
{
    Sequence *sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    string inserted1 = "teste1";
    string inserted2 = "teste2";
    
    sequence->insertBegin(new Node(inserted1));
    sequence->insertBegin(new Node(inserted2));
    
    int qtBefore = sequence->getQuantity();
    string removed1 = sequence->remove(1)->getValue();
    assert(removed1 == inserted2);
    assert(sequence->getQuantity() == qtBefore-1);
    
    qtBefore = sequence->getQuantity();
    string removed2 = sequence->remove(1)->getValue();
    assert(removed2 == inserted1);
    assert(sequence->getQuantity() == qtBefore-1);
    
    delete sequence;
    
    cout << "TestRemove OK" << endl;
}

void testAll()
{
    Sequence* sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    sequence->insertBegin( new Node("a") );
    sequence->removeBegin();
    
    sequence->insertBegin( new Node("a") );
    sequence->removeEnd();
    
    sequence->insertEnd( new Node("a") );
    sequence->removeBegin();
    
    sequence->insertEnd( new Node("a") );
    sequence->removeEnd();
    
    sequence->insertBegin(new Node("a"));
    sequence->insertBegin(new Node("b"));
    sequence->insertBegin(new Node("c"));
    
    assert( sequence->getQuantity() == 3 );
    assert( sequence->get(1)->getValue() == "c" );
    assert( sequence->get(2)->getValue() == "b" );
    assert( sequence->get(3)->getValue() == "a" );
    
    sequence->insertBegin(new Node("x"));
    assert( sequence->getQuantity() == 4 );
    assert( sequence->get(1)->getValue() == "x" );
    assert( sequence->get(2)->getValue() == "c" );
    assert( sequence->get(3)->getValue() == "b" );
    assert( sequence->get(4)->getValue() == "a" );
    
    sequence->insertEnd(new Node("l"));
    sequence->insertEnd(new Node("m"));
    sequence->insertEnd(new Node("n"));
    
    assert( sequence->getQuantity() == 7 );
    assert( sequence->get(1)->getValue() == "x" );
    assert( sequence->get(2)->getValue() == "c" );
    assert( sequence->get(3)->getValue() == "b" );
    assert( sequence->get(4)->getValue() == "a" );
    assert( sequence->get(5)->getValue() == "l" );
    assert( sequence->get(6)->getValue() == "m" );
    assert( sequence->get(7)->getValue() == "n" );
    
    assert( sequence->removeBegin()->getValue() == "x");
    
    assert( sequence->getQuantity() == 6 );
    assert( sequence->get(1)->getValue() == "c" );
    assert( sequence->get(2)->getValue() == "b" );
    assert( sequence->get(3)->getValue() == "a" );
    assert( sequence->get(4)->getValue() == "l" );
    assert( sequence->get(5)->getValue() == "m" );
    assert( sequence->get(6)->getValue() == "n" );
    
    assert( sequence->removeEnd()->getValue() == "n" );
    assert( sequence->removeBegin()->getValue() == "c");
    
    assert( sequence->getQuantity() == 4 );
    assert( sequence->get(1)->getValue() == "b" );
    assert( sequence->get(2)->getValue() == "a" );
    assert( sequence->get(3)->getValue() == "l" );
    assert( sequence->get(4)->getValue() == "m" );
    
    //delete sequence;
    
    cout << "Test OK" << endl;
}

void testInsertBegin()
{
    Sequence* sequence = new Sequence();
    assert( sequence->getQuantity() == 0 );
    
    sequence->insertBegin(new Node("a"));
    assert( sequence->getQuantity() == 1 );
    assert( sequence->get(1)->getValue() == "a" );
    
    sequence->insertBegin(new Node("b"));
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1)->getValue() == "b" );
    assert( sequence->get(2)->getValue() == "a" );
    
    sequence->insertBegin(new Node("c"));
    assert( sequence->getQuantity() == 3 );
    assert( sequence->get(1)->getValue() == "c" );
    assert( sequence->get(2)->getValue() == "b" );
    assert( sequence->get(3)->getValue() == "a" );
    
    sequence->insertBegin(new Node("x"));
    assert( sequence->getQuantity() == 4 );
    assert( sequence->get(1)->getValue() == "x" );
    assert( sequence->get(2)->getValue() == "c" );
    assert( sequence->get(3)->getValue() == "b" );
    assert( sequence->get(4)->getValue() == "a" );
    
    delete sequence;
    
    cout << "TestInsertBegin OK" << endl;
}

void testInsertEnd()
{
    Sequence* sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    sequence->insertEnd(new Node("a"));
    assert( sequence->getQuantity() == 1 );
    assert( sequence->get(1)->getValue() == "a" );
    
    sequence->insertEnd(new Node("b"));
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1)->getValue() == "a" );
    assert( sequence->get(2)->getValue() == "b" );
    
    sequence->insertEnd(new Node("c"));
    assert( sequence->getQuantity() == 3 );
    assert( sequence->get(1)->getValue() == "a" );
    assert( sequence->get(2)->getValue() == "b" );
    assert( sequence->get(3)->getValue() == "c" );
    
    sequence->insertEnd(new Node("x"));
    assert( sequence->getQuantity() == 4 );
    assert( sequence->get(1)->getValue() == "a" );
    assert( sequence->get(2)->getValue() == "b" );
    assert( sequence->get(3)->getValue() == "c" );
    assert( sequence->get(4)->getValue() == "x" );
    
    delete sequence;
    
    cout << "TestInsertEnd OK" << endl;
}

void testRemoveBegin()
{
    Sequence* sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    sequence->insertBegin(new Node("a"));
    assert( sequence->getQuantity() == 1 );
    assert( sequence->get(1)->getValue() == "a" );
    
    assert( sequence->removeBegin()->getValue() == "a" );
    assert( sequence->getQuantity()==0 );
    
    sequence->insertBegin(new Node("a"));
    sequence->insertBegin(new Node("b"));
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1)->getValue() == "b" );
    assert( sequence->get(2)->getValue() == "a" );
    
    assert( sequence->removeBegin()->getValue() == "b" );
    assert( sequence->getQuantity()== 1 );
    assert( sequence->get(1)->getValue() == "a" );
    
    sequence->insertBegin(new Node("c"));
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1)->getValue() == "c" );
    assert( sequence->get(2)->getValue() == "a" );
    
    assert( sequence->removeBegin()->getValue() == "c" );
    assert( sequence->getQuantity() == 1 );
    assert( sequence->removeBegin()->getValue() == "a" );
    assert( sequence->getQuantity() == 0 );
    
    delete sequence;
    
    cout << "TestRemoveBegin OK" << endl;
}

void testRemoveEnd()
{
    Sequence* sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    sequence->insertBegin(new Node("a"));
    assert( sequence->getQuantity() == 1 );
    assert( sequence->get(1)->getValue() == "a" );
    
    assert( sequence->removeEnd()->getValue() == "a" );
    assert( sequence->getQuantity()==0 );
    
    sequence->insertBegin(new Node("a"));
    sequence->insertBegin(new Node("b"));
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1)->getValue() == "b" );
    assert( sequence->get(2)->getValue() == "a" );
    
    assert( sequence->removeEnd()->getValue() == "a" );
    assert( sequence->getQuantity()== 1 );
    assert( sequence->get(1)->getValue() == "b" );
    
    sequence->insertEnd(new Node("c"));
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1)->getValue() == "b" );
    assert( sequence->get(2)->getValue() == "c" );
    
    assert( sequence->removeEnd()->getValue() == "c" );
    assert( sequence->getQuantity() == 1 );
    assert( sequence->removeEnd()->getValue() == "b" );
    assert( sequence->getQuantity() == 0 );
    
    delete sequence;
    
    cout << "TestInsertBegin OK" << endl;
}

int main(int argc, const char * argv[]) {
    testInsertBegin();
    testInsertEnd();
    
    testRemoveBegin();
    testRemoveEnd();
    
    testAll();
    
    testInsert();
    testRemove();
    
    return 0;
}
