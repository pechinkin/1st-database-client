class Vehicle
{
private:
    std::string brand;
    std::string model;
protected:
    char type;
//    char type; //bus - s, car - r; bike - e;
    
public:
    void SetBrand(std::string b);
    void SetModel(std::string m);
    virtual void SetType()=0;
    
    std::string GetBrand() const;
    std::string GetModel() const;
    char GetType() const;
    
//    virtual void WriteTo(std::ostream& output) = 0; //for different types it's going to be different output. can be done to file/concole/?other stream?
    
    Vehicle();
    Vehicle(std::string b, std::string m);
    Vehicle(Vehicle const &another);
    
    virtual ~Vehicle();
};

void Vehicle::SetBrand(std::string b)
{
    brand = b;
};
void Vehicle::SetModel(std::string m)
{
    model = m;
};

std::string Vehicle::GetBrand() const
{
    return brand;
};
std::string Vehicle::GetModel() const
{
    return model;
};
char Vehicle::GetType() const
{
    return type;
};

Vehicle::Vehicle()
{
    brand = "not set";
    model = "not set";
}
Vehicle::Vehicle(std::string b, std::string m): brand{b}, model{m}
{};
Vehicle::Vehicle(Vehicle const &another): brand{another.GetBrand()}, model{another.GetModel()}
{};

Vehicle::~Vehicle()
{
}
