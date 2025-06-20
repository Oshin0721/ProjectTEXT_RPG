#include "shop.h"
#include <iostream>
using namespace std;



Shop::Shop() {
	cout << "������ ���Ƚ��ϴ�!" << endl;
	cout << "�������� �����ϰų� �Ǹ��� �� �ֽ��ϴ�." << endl;
	cout << "�������� ���ϴ� �۾��� �����ϼ���." << endl;


	availableItems.push_back(make_unique<HealthPotion>("�⺻ ü�� ����", 50)); // �̸�, ����, 
	availableItems.push_back(make_unique<AttackBoost>("���ݷ� ���� ����", 70)); // �̸�, ����, 
	// �ʱ�ȭ �۾��� �ʿ��ϴٸ� ���⿡ �ۼ�
}

void Shop::displayItems() const {
	cout << "������ �ִ� ������ ���:" << endl;
	for (availableItems.empty()) {
		cout << "�������� �����ϴ�." << endl;
		return;

	}
	for (int i = 0; i < availableItems.size(); ++i) {
		cout << i + 1 << ". " << availableItems[i]->getName() << " - ����: " << availableItems[i]->getbuyprice() << endl;
	}
}
void Shop::buyItem(int index, Character* player) 
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
	int thistimegold = player->getGold();
    
    player->addItem(item.get());  
	player->addGold(player->getGold()- player->getGold());
    player->addGold(thistimegold - item->getBuyPrice());  
    cout << item->getName() << "��(��) �����߽��ϴ�!" << endl;  
}
void Shop::sellItem(int index, Character* player)
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

    
	player->addGold(player->getGold() + item->getSellPrice());//������ �Ǹ� ������ �÷��̾��� ��忡 �߰�


	player->removeItem(index);//�������� �κ��丮���� ���� �߰� ���ֽø� �����մϴ�.

    cout << item->getName() << "��(��) �Ǹ��߽��ϴ�!" << endl;
}