#pragma once
#include "bGameObject.h"
#include "bImage.h"

namespace b
{
	class Animator;
	class Peglin : public GameObject
	{
	public:
		enum class ePeglinState
		{
			ShootBall,
			ShootBomb,
			Death,
			Idle,
		};

		Peglin();
		~Peglin();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		void shoot_ball();
		void shoot_bomb();
		void death();
		void idle();

	private:
		Animator* mAnimator;
		ePeglinState mState;
	};
}

