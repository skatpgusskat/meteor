#include "stdafx.h"
#include "Character.h"

CCharacter::CCharacter(void)
	: m_Status(STAND)
{
}

CCharacter::~CCharacter(void)
{
}

bool CCharacter::HitCheck(CSkill &skill)
{
	return false;
}
