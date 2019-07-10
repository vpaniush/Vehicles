#pragma once
#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
protected:
	string name;
	string type;
	int capacity;
public:
	Vehicle()
	{
		name = "";
		type = "";
		capacity = 0;
	}
	Vehicle(string name, string type, int capacity)
	{
		this->name = name;
		this->type = type;
		this->capacity = capacity;
	}

	virtual void EnterFields() = 0;
	virtual void Print() = 0;

	string GetName()
	{
		return name;
	}
	string GetType()
	{
		return type;
	}
	int GetCapacity()
	{
		return capacity;
	}
};

class Plane :public Vehicle
{
private:
	string company;
	int height;
public:
	Plane()
	{
		company = "";
		height = 0;
	}
	Plane(string name, string type, int capacity, string company, int height) : Vehicle(name, type, capacity)
	{
		this->company = company;
		this->height = height;
	}
	void EnterFields()
	{
		cin >> name >> type >> capacity >> company >> height;
	}
	void Print()
	{
		cout << "(Plane) Name: " << name << "\tType: " << type << "\tCapacity: " << capacity << "\tCompany: " << company << "\tMax height: " << height << endl;
	}
	string GetCompany()
	{
		return company;
	}
	int GetHeight()
	{
		return height;
	}
};

class Ship :public Vehicle
{
private:
	int length;
	int depth;
public:
	Ship()
	{
		length = 0;
		depth = 0;
	}
	Ship(string name, string type, int capacity, int length, int depth) : Vehicle(name, type, capacity)
	{
		this->length = length;
		this->depth = depth;
	}
	void EnterFields()
	{
		cin >> name >> type >> capacity >> length >> depth;
	}
	void Print()
	{
		cout << "(Ship)  Name: " << name << "\tType: " << type << "\tCapacity: " << capacity << "\tLength: " << length << "\tMin depth: " << depth << endl;
	}
	int GetLength()
	{
		return length;
	}
	int GetDepth()
	{
		return depth;
	}
};