#include <iostream>
#include <queue>

struct SetElement
{
    int value;
    SetElement* left;
    SetElement* right;

    SetElement(int v)
    {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

struct IntSet
{
    SetElement* root;

    IntSet()
    {
        root = nullptr;
    }

    ~IntSet()
    {
        std::queue<SetElement*> q;
        q.push(root);
        while (!q.empty())
        {
            SetElement* cur = q.front();
            q.pop();
            if (cur != nullptr)
            {
                q.push(cur->left);
                q.push(cur->right);
                delete cur;
            }
        }
        root = nullptr;
    }

    void add(int key)
    {
        if (root == nullptr)
        {
            root = new SetElement(key);
        }
        else
        {
            SetElement* cur = root;
            while (cur != nullptr)
            {
                if (key < cur->value)
                {
                    if (cur->left == nullptr)
                    {
                        cur->left = new SetElement(key);
                        break;
                    }
                    else
                    {
                        cur = cur->left;
                    }
                }
                else if (key > cur->value)
                {
                    if (cur->right == nullptr)
                    {
                        cur->right = new SetElement(key);
                        break;
                    }
                    else
                    {
                        cur = cur->right;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    SetElement* remove(SetElement* root, int key)
    {
        if (root == nullptr) return root;

        if (key < root->value)
        {
            root->left = remove(root->left, key);
        }
        else if (key > root->value)
        {
            root->right = remove(root->right, key);
        }
        else
        {
            if (root->left == nullptr)
            {
                SetElement* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                SetElement* temp = root->left;
                delete root;
                return temp;
            }

            SetElement* temp = find(root->right);
            root->value = temp->value;
            root->right = remove(root->right, temp->value);
        }

        return root;
    }

    SetElement* find(SetElement* node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    void remove(int key)
    {
        root = remove(root, key);
    }

    void print()
    {
        std::queue<SetElement*> q;
        q.push(root);
        while (!q.empty())
        {
            SetElement* cur = q.front();
            q.pop();
            if (cur != nullptr)
            {
                q.push(cur->left);
                q.push(cur->right);
                std::cout << cur->value << " ";
            }
        }
    }
};

int main()
{
    setlocale(0, "");
    IntSet set;
    set.add(5);
    set.add(10);
    set.add(2);
    set.add(4);
    set.add(3);
    set.add(8);
    set.add(0);

    std::cout << "До удаления (удаляем цифру 5): ";
    set.print();
    std::cout << std::endl;

    set.remove(5);

    std::cout << "После удаления: ";
    set.print();
    std::cout << std::endl;

}
