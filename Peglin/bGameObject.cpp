#include "bGameObject.h"
#include "bTransform.h"

namespace b
{
	GameObject::GameObject()
		: mState(eState::Active)
	{
		mComponents.resize((UINT)eComponentType::End);
		AddComponent<Transform>();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render(hdc);
		}
	}

	void GameObject::Release()
	{
		for (Component* mcomp : mComponents)
		{
			if (mcomp == NULL) continue;

			mcomp->Release();
		}
	}

	void GameObject::OnCollisionEnter(Collider* other)
	{
	}

	void GameObject::OnCollisionStay(Collider* other)
	{
	}
	
	void GameObject::OnCollisionExit(Collider* other)
	{
	}
}