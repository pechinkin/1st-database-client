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
    
    friend std::ostream& operator<<(std::ostream& output, const Vehicle* vehicle);
    virtual std::ostream& WriteTo(std::ostream& output) const = 0;
    
    Vehicle();
    Vehicle(std::string b, std::string m);
    Vehicle(Vehicle const &another);
    
    virtual ~Vehicle();
};

std::ostream& operator<<(std::ostream& output, const Vehicle* vehicle) {
    return vehicle->WriteTo(output);
}

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
