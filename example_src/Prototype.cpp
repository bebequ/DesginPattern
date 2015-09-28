#include "config.h"

#ifdef PROTOTYPE
#include <iostream>
#include <string>
#include <map>

enum RECORD_TYPE_en
{
    CAR,
    BIKE,
    PERSON
};

class Record 
{
public :
    Record() {}
    virtual ~Record() {}
    virtual Record* clone() = 0;
    virtual void print() = 0;
};

/** 
 * CarRecord is the Concreate Prototype
 */ 
class CarRecord : public Record
{
private:
    std::string m_carName;
    int m_ID;

public :
    CarRecord(std::string carName, int ID)
        : Record()
        , m_carName(carName)
        , m_ID(ID)
    {}

    CarRecord(const CarRecord& carRecord) 
        : Record(carRecord)
    {
        m_carName = carRecord.m_carName;
        m_ID = carRecord.m_ID;
    }

    ~CarRecord() {}

    Record* clone() {
        return new CarRecord(*this);
    }

    void print()
    {
        std::cout << "Car Record" << std::endl
                  << "Name : " << m_carName << std::endl
                  << "Number : " << m_ID << std::endl << std::endl;
    }
};

/**
 * BikeRecord is the Concrete Prototype
 */
class BikeRecord : public Record
{
private:
    std::string m_bikeName;
    int m_ID;

public:
    BikeRecord(std::string bikeName, int ID) 
        : Record()
        , m_bikeName(bikeName)
        , m_ID(ID)
    {
    }
    BikeRecord(const BikeRecord& bikeRecord)
        : Record(bikeRecord)
    {
        m_bikeName = bikeRecord.m_bikeName;
        m_ID = bikeRecord.m_ID;
    }
    
    ~BikeRecord() {}
        
    Record* clone() {
        return new BikeRecord(*this);
    }
    
    void print()
    {
        std::cout << "Bike Record" <<std::endl
                  << "Name : " << m_bikeName << std::endl
                  << "Number : " << m_ID << std::endl << std::endl;
    }
};

/**
 * PersonRecord is the Concrete Prototype
 */
class PersonRecord : public Record
{
private:
    std::string m_personName;
    int m_age;

public:
    PersonRecord(std::string personName, int age)
        : Record()
        , m_personName(personName)
        , m_age(age)
    {

    }
    PersonRecord(const PersonRecord& personRecord)
        : Record(personRecord)
    {
        m_personName = personRecord.m_personName;
        m_age = personRecord.m_age;
    }
    
    ~PersonRecord() {}
    
    Record* clone()
    {
        return new PersonRecord(*this);
    }

    void print()
    {
        std::cout <<"Person Record" << std::endl
            << "Name : " << m_personName << std::endl
            << "Age : " << m_age << std::endl << std::endl;
    }
};

/**
 * RecordFactory is the client
 */
class RecordFactory
{
private:
    std::map<RECORD_TYPE_en, Record*> m_recordReference;
public:
    RecordFactory() 
    {
        m_recordReference[CAR] = new CarRecord("Ferrari", 5050);
        m_recordReference[BIKE] = new BikeRecord("Yamaha", 2525);
        m_recordReference[PERSON] = new PersonRecord("Tom", 25);
    }

    ~RecordFactory()
    {
        delete m_recordReference[CAR];
        delete m_recordReference[BIKE];
        delete m_recordReference[PERSON];
    }

    Record* createRecord(RECORD_TYPE_en enType)
    {
        return m_recordReference[enType]->clone();
    }
};

int main(int argc, char* argv[])
{
    
    RecordFactory* poRecordFactory = new RecordFactory();

    Record* poRecord;
    poRecord = poRecordFactory->createRecord(CAR);
    poRecord->print();
    delete poRecord;

    poRecord = poRecordFactory->createRecord(BIKE);
    poRecord->print();
    delete poRecord;

    poRecord = poRecordFactory->createRecord(PERSON);
    poRecord->print();
    delete poRecord;

    delete poRecordFactory;

    char c;
    std::cin >> c;

    return 0;
}
#endif
