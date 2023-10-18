class Bus : public Vehicle
{
private:
    int sitting_pasangers;  //>0
    int max_passangers;     //>=sitting
    std::string destination;

    
public:
    void SetSittingPas(int s);
    void SetMaxPas(int m);
    void SetDestination(std::string d);
    void SetType() override;
    
    int GetSittingPas() const;
    int GetMaxPas() const;
    std::string GetDestination() const;
    
//    void WriteTo(std::ostream& output) override;
    std::ostream& WriteTo(std::ostream& output) const override;
    
    Bus();
    Bus(std::string b, std::string m, int sit, int max, std::string d);
    Bus(Bus const &another);
};

void Bus::SetSittingPas(int s)
{
    sitting_pasangers = s;
};
void Bus::SetMaxPas(int m)
{
    max_passangers = m;
};
void Bus::SetDestination(std::string d)
{
    destination = d;
};
void Bus::SetType()
{
    type = 's';
};

int Bus::GetSittingPas() const
{
    return sitting_pasangers;
};
int Bus::GetMaxPas() const
{
    return max_passangers;
};
std::string Bus::GetDestination() const
{
    return destination;
};

std::ostream& Bus::WriteTo(std::ostream& output) const {
    output << "Brand:\n" << GetBrand() << "\nModel:\n" << GetModel() << "\nSit. passangers:\n"
    << sitting_pasangers << "\nMax. passangers:\n" << max_passangers << "\nDestination:\n" << destination;
    return output;
}

Bus::Bus(): Vehicle()
{
    sitting_pasangers = 0;  //>0
    max_passangers = 0;     //>=sitting
    destination = "not set";
    SetType();
};
Bus::Bus(std::string b, std::string m, int sit, int max, std::string d):
Vehicle(b, m), sitting_pasangers{sit}, max_passangers{max}, destination{d}
{
    SetType();
};
Bus::Bus(Bus const &another):
Vehicle(another.GetBrand(), another.GetModel()), sitting_pasangers{another.GetSittingPas()},
max_passangers{another.GetMaxPas()}, destination{another.GetDestination()}
{
    SetType();
};
