//
//  ArraySequence.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "Sequence.h"
#include "Node.h"

Node **content;
const int SIZE = 7;
unsigned int init;
unsigned int end;

Sequence::Sequence()
{
    content = new Node*[SIZE];
    this->quantity = 0;
    init = 0;
    end = 0;
}

Sequence::~Sequence()
{
    // TO - DO
    delete [] content;
}

/**
 Returns the i-th element in this sequence.
 */
Node* Sequence::get(int i)
{
    return content[i-1];
}

/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
void Sequence::insert(int i, Node* element)
{
    // TO - DO
}

/**
 Inserts the element in the begin of this sequence.
 After inserting, the element will be the first in the sequence.
 */
void Sequence::insertBegin(Node* element)
{
    if( this->isEmpty()){
        content[init] = element;
    }
    
    else{    
        
        for (int i = this->quantity; i >=0 ; i--)
        {
             content[i+1] = content[i];       
        }
        content[init] = element;
                
    }
this->quantity++;
end++;    

}

/**
 Inserts the element in the end position of this sequence.
 After inserting, the element will be the last in the sequence.
 */
void Sequence::insertEnd(Node* element)
{
    
    if (this->isEmpty()){
        content[init] = element;
    }
    else{
        content[end] = element;
    }
    end++;
    this->quantity++;

    
}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
Node* Sequence::remove(int i)
{
    // TO - DO
    return nullptr;
}

/**
 Removes the first element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeBegin()
{
    if(this->isEmpty()){
        return nullptr;
    }
    else{
        Node *aux = new Node(content[init]->getValue());
        for(int i = (int)init; i<=(int)end;i++){
            content[i] = content[i+1];
        }
        end--;
        this->quantity--;
        return aux;
     }

}    


/**
 Removes the last element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeEnd()
{    
    if (this->isEmpty()){
        return nullptr;
    }
    else{
        Node *aux = new Node(content[end-1]->getValue());
        //content[end-1] = content[end];
        this->quantity--;
        end--;
        return aux;
    }
}

bool Sequence::isEmpty()
{
    return this->getQuantity()==0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
