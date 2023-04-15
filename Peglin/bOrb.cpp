#include "bOrb.h"
#include "bAnimator.h"
#include "bTransform.h"
#include "bInput.h"
#include "bRigidbody.h"
#include "bObject.h"

namespace b
{
	Orb::Orb()
		: mAnimator(nullptr)
		, mRigidbody(nullptr)
		, bShoot(false)
		, mForce(Vector2::One)
	{
	}

	Orb::~Orb()
	{
	}

	void Orb::Initialize()
	{
		GameObject::Initialize();

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimations(L"..\\Resources\\sprite\\Ball\\Rock", Vector2::Zero, 0.1f);

		mAnimator->Play(L"BallRock", true);

		mRigidbody = AddComponent<Rigidbody>();
		mRigidbody->SetMass(1.0f);
		mRigidbody->SetGravity(Vector2::Zero);
		mRigidbody->SetGround(false);
	}

	void Orb::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (pos.y > 900.0f)
			object::Destory(this);

		if (!bShoot && Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			bShoot = true;
			
			Vector2 dir = Input::GetMousePos();
			dir -= pos;
			dir.Normalize();
			mForce = dir * 17000;
			mRigidbody->SetForce(mForce);
			mRigidbody->SetGravity(Vector2(0.0f, 400.0f));


		}

		GameObject::Update();
	}

	void Orb::Render(HDC hdc)
	{
		HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);

		if (!bShoot)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 mPos = tr->GetPos();
			Vector2 mousePos = Input::GetMousePos();

			MoveToEx(hdc, mPos.x + 10, mPos.y, NULL);
			LineTo(hdc, mousePos.x, mousePos.y);
		}

		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(pen);

		GameObject::Render(hdc);
	}

	void Orb::Release()
	{
		GameObject::Release();
	}

	void Orb::OnCollisionEnter(Collider* other)
	{
	}

	void Orb::OnCollisionStay(Collider* other)
	{
	}

	void Orb::OnCollisionExit(Collider* other)
	{
	}
}