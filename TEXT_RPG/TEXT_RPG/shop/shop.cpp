#include "shop.h"
#include <iostream>
using namespace std;



Shop::Shop(Character* player) : player(player) {
    
    availableItems.push_back(make_unique<HealthPotion>("�⺻ ü�� ����", 50)); // �̸�, ����, 
    availableItems.push_back(make_unique<AttackBoost>("���ݷ� ���� ����", 70)); // �̸�, ����, 

    // interact() �Լ��� �̿��ؼ� ������ ��ȣ�ۿ��ϵ��� ��.
	cout << "������ ���Ƚ��ϴ�!" << endl; 
	cout << "�������� �����ϰų� �Ǹ��� �� �ֽ��ϴ�." << endl;
	cout << "�������� ���ϴ� �۾��� �����ϼ���." << endl;
	cout << "1. ������ ����" << endl;
	cout << "2. ������ �Ǹ�" << endl;
	cout << "3. ���� ����" << endl;

	int choice;
	cin >> choice;
    if(choice == 1) {
        displayItems();
        int itemIndex;
        cout << "������ �������� ��ȣ�� �Է��ϼ���: ";
        cin >> itemIndex;
        buyItem(itemIndex - 1); // �ε����� 0���� �����ϹǷ� -1
    } else if (choice == 2) {
        if (player->getInventorySize() == 0) {
            cout << "�κ��丮�� �������� �����ϴ�." << endl;
            return;
        }
        player->displayInventory();
        int itemIndex;
        cout << "�Ǹ��� �������� ��ȣ�� �Է��ϼ���: ";
        cin >> itemIndex;
        sellItem(itemIndex - 1); // �ε����� 0���� �����ϹǷ� -1
    } else if (choice == 3) {
        cout << "������ �����մϴ�." << endl;
    } else if (choice == 44){
        cout << "������ �ڵ��Դϴ�" << endl;

	}   


	
	// �ʱ�ȭ �۾��� �ʿ��ϴٸ� ���⿡ �ۼ�
}

void Shop::displayItems() const {
	cout << "������ �ִ� ������ ���:" << endl;
	if (availableItems.empty()) {
		cout << "�������� �����ϴ�." << endl;
        cout << "----------------------" << endl;
		return;

	}
	for (int i = 0; i < availableItems.size(); ++i) {
		cout << i + 1 << ". " << availableItems[i]->getName() << " - ����: " << availableItems[i]->getBuyPrice() << endl;
	}
}
void Shop::buyItem(int index) 
{  
    if (index < 0 || index >= availableItems.size())
    {  
        cout << "�߸��� ������ �����Դϴ�." << endl;  
        return;  
    }  
    auto& item = availableItems[index];  
    if (player->getGold() < item->getBuyPrice())
    {  
        cout << "��尡 �����մϴ�." << endl;  
        return;  
    }  
	
    
    player->addItem(item.get());
    player->addGold(-item->getBuyPrice());
    cout << item->getName() << "��(��) �����߽��ϴ�!\n";
}
void Shop::sellItem(int index)
{    
    if (index < 0 || index >= player->getInventorySize())
    { 
        cout << "�߸��� ������ �����Դϴ�." << endl;
        return;
    }
    if (player->getInventorySize() == 0) {
        cout << "�κ��丮�� �������� �����ϴ�." << endl;
        return;
    }

    
	Item* item = player->getItem(index); //������ �κ��丮���� ��������
    string itemName = item->getName(); // �����ϰ� �̸��� ����
    
	player->addGold(player->getGold() + item->getSellPrice());//������ �Ǹ� ������ �÷��̾��� ��忡 �߰�


	player->removeItem(index);//�������� �κ��丮���� ���� �߰� ���ֽø� �����մϴ�.

    cout << itemName << "��(��) �Ǹ��߽��ϴ�!" << endl;
}
