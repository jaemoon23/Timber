#include "stdafx.h"
#include "Tree.h"


void Tree::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	tree.setPosition(pos);
	for (int i = 0; i < branches.size(); i++)
	{
		branches[i].setPosition(pos.x, i * 150.f);
	}
}

Sides Tree::UpdateBranches()
{
	for (int i = branchesSides.size() - 1; i > 0 ; i--)
	{
		branchesSides[i] = branchesSides[i - 1];
	}
	branchesSides[0] = (Sides)Utils::RandomRange(0, 3);
	for (int i = 0; i < branchesSides.size() - 1; i++)
	{
		switch (branchesSides[i])
		{
		case Sides::Left:
			branches[i].setScale(-1.f, 1.f);
			break;
		case Sides::Right:
			branches[i].setScale(1.f, 1.f);
			break;
		default:
			break;
		}
	}
	return branchesSides[0];
}

void Tree::Init()
{
	texIdTree = "graphics/tree.png";
	texIdBranch = "graphics/branch.png";

	branches.resize(6);
	branchesSides.resize(6);
}

void Tree::Release()
{

}

void Tree::Reset()
{
	tree.setTexture(TEXTURE_MGR.Get(texIdTree), true);
	Utils::SetOrigin(tree, Origins::TC);

	sf::FloatRect bounds = tree.getLocalBounds();

	for (int i = 0; i < branches.size() - 1; i++)
	{
		branches[i].setTexture(TEXTURE_MGR.Get(texIdBranch));
		branches[i].setOrigin(bounds.width * -0.5f, 0.f);

		branchesSides[i] = (Sides)Utils::RandomRange(0, 3);
		
		switch (branchesSides[i])
		{
			case Sides::Left:
				branches[i].setScale(-1.f,1.f);
				break;
			case Sides::Right:
				branches[i].setScale(1.f, 1.f);
				break;
		default:
			break;
		}

	}
	branchesSides[branches.size() - 1] = Sides::None;

	sf::FloatRect windowBounds = FRAMEWORK.GetWindowBounds();
	SetPosition({ windowBounds.width * 0.5f, 0.f });
}

void Tree::Update(float dt)
{
	
}

void Tree::Draw(sf::RenderWindow& window)
{
	window.draw(tree);

	for (int i = 0; i < branches.size(); i++)
	{
		if (branchesSides[i] != Sides::None)
		{
			window.draw(branches[i]);
		}
	}
}
