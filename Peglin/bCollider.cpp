#include "bCollider.h"
#include "bTransform.h"
#include "bGameObject.h"

namespace b
{
	Collider::Collider()
		: Component(eComponentType::Collider)
		, mCenter(Vector2::Zero)
		, mSize(Vector2(100.0f, 100.0f))
		, mScale(Vector2::Zero)
		, mPos(Vector2::Zero)
	{
	}

	Collider::~Collider()
	{
	}

	void Collider::Initialize()
	{
	}

	void Collider::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		mPos = tr->GetPos() + mCenter;
	}

	void Collider::Render(HDC hdc)
	{
		HPEN pen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);
		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, mPos.x, mPos.y, mPos.x + mSize.x, mPos.y + mSize.y);

		(HPEN)SelectObject(hdc, oldPen);
		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(pen);
	}

	void Collider::Release()
	{
	}
}