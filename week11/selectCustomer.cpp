#include <iostream>
#include <string>
#include<vector> //�����迭 ����ϱ� ���� 
using namespace std;

class Person {
	string name;
	int age;
	Person(string name ,int age) {
		this->name = name;
		this ->age = age;
	}
};
int main() {

	int maxPeople; 
	// �ʱ�ȭ ���� ������ �迭 ������ �ȵǹǷ� ����� �ʱ�ȭ 
	
	cout << "�� ���� ���� �Է��϶�";
	cin >> maxPeople;

	// ���� �迭 ���� 
	vector<Person> people;

	//���� ����
	string name;
	int age;
	
	// �ݺ����� ����¹��� ȥ���Ͽ� �迭�� ��� 1~3�� ������ �Է¹޴´�. 
	for (int i = 0; i < maxPeople; i++) {
		cout << "���" << i+1 << "�� �̸� :";
		cin >> name;
		cout << "���" << i << "�� ���� :"; 
		cin >> age;
		people = Person(name, age);
		people.push_back(people);
		
	}


	int ageThreshold; // �������� ������ ����� Ư�� ���� 
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���:";

	cin >> ageThreshold; // Ư�� ���� �Է¹��� 
	cout << ageThreshold << "�� �̻��� ����: \n";
	
	//������ �����ϴ� ����� ���� �Է¹޴� ���� ���� 
	int count = 0;
	
	//�ݺ����� ���� ������ �����ϴ� ����� ���� ī��Ʈ 
	for (int i = 0; i < 3; i++) {
		if (ages[i] >= ageThreshold) {
			count++;
		}
	}

	//ī��Ʈ�� 0���� ū��� �ش��ϴ� ������� �̸��� ���̸� ��� 
	//ī��Ʈ�� ���°�� Ư�� ���̺��� ���� ���� ���� �޽����� ����Ѵ�.
	if (count > 0) {
		for (int i = 0; i < count; i++) {
			if (ages[i] >= ageThreshold) {
				cout << names[i] << " (" << ages[i] << "��) " << endl;
			}
		}
	}
	else {
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�.";
	}
}
