#pragma once
#include <string>
#include <iostream>

class Event
{
public:
  Event(const int id,
        const std::string &nameOfAction,
        const std::string &description) : id(id), nameOfAction(nameOfAction), description(description)
  {
  }

  Event() = default;

  int getId() const { return id; }
  std::string getNameOfAction() const { return nameOfAction; }
  std::string getDescription() const { return description; }

  void setId(const int _id)
  {
    id = _id;
  }
  void setNameOfAction(const std::string &_nameOfAction)
  {
    nameOfAction = _nameOfAction;
  }

  void setDescription(const std::string &_description)
  {
    description = _description;
  }

  friend std::ostream &operator<<(std::ostream &os, const Event &obj);

private:
  int id;
  std::string nameOfAction;
  std::string description;
};
