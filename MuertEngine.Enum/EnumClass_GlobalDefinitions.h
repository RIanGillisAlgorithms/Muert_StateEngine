

//by ian.gillis
#pragma once
#ifndef EnumClass_GlobalDefinitions_H
#define EnumClass_GlobalDefinitions_H
// EnumClass_GlobalDefinitions.h
// by ian.gillis

#include <type_traits>			
#include "enum_mapping.h"
#include "enum_array.h"

//template <typename E>
//constexpr auto to_underlying(E e) noexcept
//{
//	return static_cast<std::underlying_type_t<E>>(e);
//}





enum class CursorDelimiter
{
	OpenSquareBracket
	, CloseSquareBracket
	, OpenCurlyBracket
	, CloseCurlyBracket
	, OpenAngleBracket
	, CloseAngleBracket
	, OpenParenthesis
	, CloseParenthesis
	, DoubleQuote
	, SingleQuote
	, Colon
	, SemiColon
	, Comma
	, Period
	, Slash
	, BackSlash
	, VerticalPipe
	, Tilde
	, GraveAccent
	, ExclamationMark
	, AtSign
	, Octothorpe
	, Dollar
	, Percent
	, Carat
	, Ampersand
	, Asterisk
	, Underscore
	, Hyphen
	, Plus
	, Equal
	, QuestionMark

	, STATE_COUNT
};
const std::array<const EnumMapping::NameValuePair<CursorDelimiter>, 31 > v_CursorDelimiter{ {
	{CursorDelimiter::OpenSquareBracket, "["},
	{CursorDelimiter::CloseSquareBracket, "]"},
	{CursorDelimiter::OpenCurlyBracket, "{"},
	{CursorDelimiter::CloseCurlyBracket, "}"},
	{CursorDelimiter::OpenParenthesis, "("},
	{CursorDelimiter::CloseParenthesis, ")"},
	{CursorDelimiter::DoubleQuote, "\""},
	{CursorDelimiter::SingleQuote, "'"},
	{CursorDelimiter::Colon, ":"},
	{CursorDelimiter::SemiColon, ";"},
	{CursorDelimiter::Comma, ","},
	{CursorDelimiter::Period, "."},
	{CursorDelimiter::Slash, "/"},
	{CursorDelimiter::BackSlash, "\\"},
	{CursorDelimiter::VerticalPipe, "|"},
	{CursorDelimiter::Tilde, "~"},
	{CursorDelimiter::GraveAccent, "`"},
	{CursorDelimiter::ExclamationMark, "!"},
	{CursorDelimiter::AtSign, "@"},
	{CursorDelimiter::Octothorpe, "#"},
	{CursorDelimiter::Dollar, "$"},
	{CursorDelimiter::Percent, "%"},
	{CursorDelimiter::Carat, "^"},
	{CursorDelimiter::Ampersand, "&"},
	{CursorDelimiter::Asterisk, "*"},
	{CursorDelimiter::Underscore, "_"},
	{CursorDelimiter::Hyphen, "-"},
	{CursorDelimiter::Plus, "+"},
	{CursorDelimiter::Equal, "="},
	{CursorDelimiter::QuestionMark, "?"},
	{CursorDelimiter::STATE_COUNT, ""},
} };

namespace GLOBAL
{
	enum class gameStates
	{

		QUIT = 0,
		CLEAN_UP,

		STATE_COUNT
	};

	enum class GLSurfaceMorphability
	{
		MUST_BE_WHOLE_TILE = 0,
		SHOULD_BE_WHOLE_TILE = 1,
		CAN_BE_WHOLE_TILE = 2,

		STATE_COUNT
	};

	enum class ActionState
	{
		NONE = 0,
		PANNING,
		PANNING_MSG,
		PANNING_STATS,
		SELECTING,
		CENTERINGSCREEN,
		ADJUSTMSG,
		ADJUSTSTATS,
		DEPRESSBUTTON,
		LEFTCLICK,
		RIGHTCLICK,
		MIDDLECLICK,
		ADJUST_SURFACE,

		STATE_COUNT

	};
}

namespace DRAW
{
	enum class VPAType
	{
		Button,
		ButtonWithDisplay,
		Slider,

		STATE_COUNT

	};

	enum class VPABorderWidth
	{
		none = 0,
		half = 1,
		full = 2,
		oneHalf = 3,
		dbbl = 4,

		STATE_COUNT

	};
	enum class ViewPortLayoutLocations
	{
		NoValidLocation = 0,
		Up,
		Down,
		UpLeft,
		UpRight,
		DownLeft,
		DownRight,
		UpDownBuffer,

		STATE_COUNT
	};

	enum class LAYOUT_TYPE
	{
		FullScreenTile = 0
		, FullScreenTile_EmptySpace
		, FullScreenTile_Begin
		, FullScreenTile_Terraform
		, FullScreenTile_Terraform_World
		, FullScreenTile_Terraform_Area
		, FullScreenTile_Terraform_Region
		, FullScreenTile_Terraform_Local

		, FullScreenTile_God
		, FullScreenTile_Space_World
		, FullScreenTile_Space_Area
		, FullScreenTile_Space_Region
		, FullScreenTile_Space_Local

		, PixelDisplay
		, MessageDisplay

		, StatsDisplay
		, StatsDisplay_System
		, StatsDisplay_Begin
		, StatsDisplay_Terraform
		, StatsDisplay_SelectMap
		, StatsDisplay_God
		, StatsDisplay_DefineRegion

		, StatsDisplay_fUniverse
		, StatsDisplay_qUniverse
		, StatsDisplay_qMegaParsec

		, StatsDisplay_System_Stats

		, StatsDisplay_vUniverse
		, StatsDisplay_lUniverse

		, Menu_Control
		, Menu_Stats_Control

		, Sys_Lower
		, Sys_Border_Top
		, Sys_Border_Bottom

		, OptionDisplay

		, fUniverse
		, fRegion
		, fLocal

		, qUniverse
		, qMegaParsec
		, qKiloParsec
		, qParsec
		, qAntiKiloParsec
		, qAntiMegaParsec
		, qAntiGigaParsec
		, qGod
		, qWorld
		, qArea
		, qRegion
		, qLocal


		, roomEditor

		, vUniverse
		, lUniverse


		, fastMap_Unfathomable
		, fastMap_GigaParsec
		, fastMap_MegaParsec
		, fastMap_KiloParsec
		, fastMap_Parsec
		, fastMap_MilliParsec
		, fastMap_MicroParsec
		, fastMap_NanoParsec


		, STATE_COUNT
	};
	const std::array<const EnumMapping::NameValuePair<LAYOUT_TYPE>, (int)LAYOUT_TYPE::STATE_COUNT + 1 > v_LAYOUT_TYPE{ {
		{LAYOUT_TYPE::FullScreenTile, "Full-Screen Tile"},
		{ LAYOUT_TYPE::FullScreenTile_EmptySpace, "Full-Screen Tile (Empty Space)" },
		{ LAYOUT_TYPE::FullScreenTile_Begin, "Full-Screen Tile (Begin)" },
		{ LAYOUT_TYPE::FullScreenTile_Terraform, "Full-Screen Tile (Terraform)" },
		{ LAYOUT_TYPE::FullScreenTile_Terraform_World, "Full-Screen Tile (Terraform World)" },
		{ LAYOUT_TYPE::FullScreenTile_Terraform_Area, "Full-Screen Tile (Terraform Area)" },
		{ LAYOUT_TYPE::FullScreenTile_Terraform_Region, "Full-Screen Tile (Terraform Region)" },
		{ LAYOUT_TYPE::FullScreenTile_Terraform_Local, "Full-Screen Tile (Terraform Local)" },
		{ LAYOUT_TYPE::FullScreenTile_God, "Full-Screen Tile (God)" },
		{ LAYOUT_TYPE::FullScreenTile_Space_World, "Full-Screen Tile (Space World)" },
		{ LAYOUT_TYPE::FullScreenTile_Space_Area, "Full-Screen Tile (Space Area)" },
		{ LAYOUT_TYPE::FullScreenTile_Space_Region, "Full-Screen Tile (Space Region)" },
		{ LAYOUT_TYPE::FullScreenTile_Space_Local, "Full-Screen Tile (Space Local)" },

		{ LAYOUT_TYPE::PixelDisplay, "Pixel Display" },
		{ LAYOUT_TYPE::MessageDisplay, "Message Display" },

		{ LAYOUT_TYPE::StatsDisplay, "Stats Display" },
		{ LAYOUT_TYPE::StatsDisplay_System, "Stats Display (System)" },
		{ LAYOUT_TYPE::StatsDisplay_Begin, "Stats Display (Begin)" },
		{ LAYOUT_TYPE::StatsDisplay_Terraform, "Stats Display (Terraform)" },
		{ LAYOUT_TYPE::StatsDisplay_SelectMap, "Stats Display (Select Map)" },
		{ LAYOUT_TYPE::StatsDisplay_God, "Stats Display (God)" },
		{ LAYOUT_TYPE::StatsDisplay_DefineRegion, "Stats Display (Define Region)" },
		{ LAYOUT_TYPE::StatsDisplay_fUniverse, "Stats Display (fUniverse)" },
		{ LAYOUT_TYPE::StatsDisplay_qUniverse, "Stats Display (qUniverse)" },
		{ LAYOUT_TYPE::StatsDisplay_qMegaParsec, "Stats Display (qMega-Parsec)" },
		{ LAYOUT_TYPE::StatsDisplay_System_Stats, "Stats Display (System Stats)" },
		{ LAYOUT_TYPE::StatsDisplay_vUniverse, "Stats Display (vUniverse)" },
		{ LAYOUT_TYPE::StatsDisplay_lUniverse, "Stats Display (lUniverse)" },

		{ LAYOUT_TYPE::Menu_Control, "Menu Control" },
		{ LAYOUT_TYPE::Menu_Stats_Control, "Menu Stats Control" },

		{ LAYOUT_TYPE::Sys_Lower, "Sys-Lower" },
		{ LAYOUT_TYPE::Sys_Border_Top, "Sys-Border (Top)" },
		{ LAYOUT_TYPE::Sys_Border_Bottom, "Sys-Border (Bottom)" },

		{ LAYOUT_TYPE::OptionDisplay, "Options Display" },

		{ LAYOUT_TYPE::fUniverse, "fUniverse" },
		{ LAYOUT_TYPE::fRegion, "fRegion" },
		{ LAYOUT_TYPE::fLocal, "fLocal" },

		{ LAYOUT_TYPE::qUniverse, "qUniverse" },
		{ LAYOUT_TYPE::qMegaParsec, "qMegaParsec" },
		{ LAYOUT_TYPE::qKiloParsec, "qKiloParsec" },
		{ LAYOUT_TYPE::qParsec, "qParsec" },
		{ LAYOUT_TYPE::qAntiKiloParsec, "qAntiKiloParsec" },
		{ LAYOUT_TYPE::qAntiMegaParsec, "qAntiMegaParsec" },
		{ LAYOUT_TYPE::qAntiGigaParsec, "qAntiGigaParsec" },
		{ LAYOUT_TYPE::qGod, "qGod" },
		{ LAYOUT_TYPE::qWorld, "qWorld" },
		{ LAYOUT_TYPE::qArea, "qArea" },
		{ LAYOUT_TYPE::qRegion, "qRegion" },
		{ LAYOUT_TYPE::qLocal, "qLocal" },


		{ LAYOUT_TYPE::vUniverse, "vUniverse" },
		{ LAYOUT_TYPE::lUniverse, "lUniverse" },

		{ LAYOUT_TYPE::fastMap_Unfathomable, "fastMap_Unfathomable" },
		{ LAYOUT_TYPE::fastMap_GigaParsec, "fastMap_GigaParsec" },
		{ LAYOUT_TYPE::fastMap_MegaParsec, "fastMap_MegaParsec" },
		{ LAYOUT_TYPE::fastMap_KiloParsec, "fastMap_KiloParsec" },
		{ LAYOUT_TYPE::fastMap_Parsec, "fastMap_Parsec" },
		{ LAYOUT_TYPE::fastMap_MilliParsec, "fastMap_MilliParsec" },
		{ LAYOUT_TYPE::fastMap_MicroParsec, "fastMap_MicroParsec" },
		{ LAYOUT_TYPE::fastMap_NanoParsec, "fastMap_NanoParsec" },


		{ LAYOUT_TYPE::STATE_COUNT, "STATE_COUNT" },
		} };

	enum class ELEMENT_LAYOUT_TYPE
	{
		SINGULAR = 0,
		VERTICAL,
		HORIZONTAL,

		STATE_COUNT
	};
	const std::array<const EnumMapping::NameValuePair<ELEMENT_LAYOUT_TYPE>, (int)ELEMENT_LAYOUT_TYPE::STATE_COUNT + 1 > v_ELEMENT_LAYOUT_TYPES{ {
		{ELEMENT_LAYOUT_TYPE::SINGULAR, "Singular"},
		{ ELEMENT_LAYOUT_TYPE::VERTICAL, "Vertical" },
		{ ELEMENT_LAYOUT_TYPE::HORIZONTAL, "Horizontal" },
		{ ELEMENT_LAYOUT_TYPE::STATE_COUNT, "STATE_COUNT" },
		} };

	enum class ELEMENT_LAYOUT_ORIENTATION
	{
		NOT_APPLICABLE = 0,
		TOP_TO_BOTTOM,
		BOTTOM_TO_TOP,
		TOP_TO_BOTTOM_REVERSED,
		BOTTOM_TO_TOP_REVERSED,
		LEFT_TO_RIGHT,
		RIGHT_TO_LEFT,
		LEFT_TO_RIGHT_REVERSED,
		RIGHT_TO_LEFT_REVERSED,

		STATE_COUNT
	};
	const std::array<const EnumMapping::NameValuePair<ELEMENT_LAYOUT_ORIENTATION>, (int)ELEMENT_LAYOUT_ORIENTATION::STATE_COUNT + 1 > v_ELEMENT_LAYOUT_ORIENTATION{ {
		{ELEMENT_LAYOUT_ORIENTATION::NOT_APPLICABLE, "Not Applicable"},
		{ ELEMENT_LAYOUT_ORIENTATION::TOP_TO_BOTTOM, "Top to Bottom" },
		{ ELEMENT_LAYOUT_ORIENTATION::BOTTOM_TO_TOP, "Bottom to Top" },
		{ ELEMENT_LAYOUT_ORIENTATION::TOP_TO_BOTTOM_REVERSED, "Top to Bottom (Reversed)" },
		{ ELEMENT_LAYOUT_ORIENTATION::BOTTOM_TO_TOP_REVERSED, "Bottom to Top (Reversed)" },
		{ ELEMENT_LAYOUT_ORIENTATION::LEFT_TO_RIGHT, "Left to Right" },
		{ ELEMENT_LAYOUT_ORIENTATION::RIGHT_TO_LEFT, "Right to Left" },
		{ ELEMENT_LAYOUT_ORIENTATION::LEFT_TO_RIGHT_REVERSED, "Left to Right (Reversed)" },
		{ ELEMENT_LAYOUT_ORIENTATION::RIGHT_TO_LEFT_REVERSED, "Right to Left (Reversed)" },
		{ ELEMENT_LAYOUT_ORIENTATION::STATE_COUNT, "STATE_COUNT" },
		} };


	enum class ELEMENT_TYPES
	{
		//FullScreen
		//, PixelDisplay
		//, MessageDisplay
		//, StatsDisplay
		//, OptionDisplay


		TileMap = 0
		, PixelRow
		, PixelColumn
		, RectangularString
		, StatDisplay
		, OptionDisplay
		, StatOptionDisplay

		, FullScreen
		, Button
		, TextBox

		, STATE_COUNT
	};
	const std::array<const EnumMapping::NameValuePair<ELEMENT_TYPES>, (int)ELEMENT_TYPES::STATE_COUNT + 1 > v_ELEMENT_TYPES{ {
		{ELEMENT_TYPES::TileMap, "Tile Map"},
		{ ELEMENT_TYPES::PixelRow, "Pixel Row" },
		{ ELEMENT_TYPES::PixelColumn, "Pixel Column" },
		{ ELEMENT_TYPES::RectangularString, "Rectangular String" },
		{ ELEMENT_TYPES::StatDisplay, "Stat Display" },
		{ ELEMENT_TYPES::OptionDisplay, "Option Display" },
		{ ELEMENT_TYPES::StatOptionDisplay, "Stat Option Display" },
		{ ELEMENT_TYPES::FullScreen, "Full-Screen" },
		{ ELEMENT_TYPES::Button, "Button" },
		{ ELEMENT_TYPES::TextBox, "Text Box" },
		{ ELEMENT_TYPES::STATE_COUNT, "STATE_COUNT" },
		} };

	enum class CONSOLE_COLOR
	{
		BLACK
		, DARK_BLUE
		, DARK_GREEN
		, DARK_CYAN
		, DARK_RED
		, DARK_MAGENTA
		, DARK_YELLOW
		, DARK_WHITE
		, BRIGHT_BLACK
		, BRIGHT_BLUE
		, BRIGHT_GREEN
		, BRIGHT_CYAN
		, BRIGHT_RED
		, BRIGHT_MAGENTA
		, BRIGHT_YELLOW
		, WHITE

		, STATE_COUNT
	};

	const std::array<const EnumMapping::NameValuePair<CONSOLE_COLOR>, (int)CONSOLE_COLOR::STATE_COUNT + 1 > v_CONSOLE_COLOR{ {
		{CONSOLE_COLOR::BLACK, "Black"}
		, {CONSOLE_COLOR::DARK_BLUE, "Dark Blue"}
		, {CONSOLE_COLOR::DARK_GREEN, "Dark Green"}
		, {CONSOLE_COLOR::DARK_CYAN, "Dark Cyan"}
		, {CONSOLE_COLOR::DARK_RED, "Dark Red"}
		, {CONSOLE_COLOR::DARK_MAGENTA, "Dark Magenta"}
		, {CONSOLE_COLOR::DARK_YELLOW, "Dark Yellow"}
		, {CONSOLE_COLOR::DARK_WHITE, "Dark White"}
		, {CONSOLE_COLOR::BRIGHT_BLACK, "Dark Black"}
		, {CONSOLE_COLOR::BRIGHT_BLUE, "Bright Blue"}
		, {CONSOLE_COLOR::BRIGHT_GREEN, "Bright Green"}
		, {CONSOLE_COLOR::BRIGHT_CYAN, "Bright Cyan"}
		, {CONSOLE_COLOR::BRIGHT_RED, "Bright Red"}
		, {CONSOLE_COLOR::BRIGHT_MAGENTA, "Bright Magenta"}
		, {CONSOLE_COLOR::BRIGHT_YELLOW, "Bright Yellow"}
		, {CONSOLE_COLOR::WHITE, "White"}

		, { CONSOLE_COLOR::STATE_COUNT, "STATE_COUNT" }
		}
	};
}

namespace Spatial
{
	enum class dir
	{
		down = 0
		, Down = 0
		, southWest = 1
		, SouthWest = 1
		, south = 2
		, South = 2
		, southEast = 3
		, SouthEast = 3
		, west = 4
		, West = 4
		, east = 6
		, East = 6
		, northWest = 7
		, NorthWest = 7
		, north = 8
		, North = 8
		, northEast = 9
		, NorthEast = 9
		, up = 5
		, Up = 5

		, STATE_COUNT = 10
	};
	const std::array<const EnumMapping::NameValuePair<dir>, 21 > v_dir{ {
		{dir::southWest, "South West"},
		{dir::SouthWest, "South West"},
		{dir::south, "South"},
		{dir::South, "South"},
		{dir::southEast, "South East"},
		{dir::SouthEast, "South East"},
		{dir::west, "West"},
		{dir::West, "West"},
		{dir::east, "East"},
		{dir::East, "East"},
		{dir::northWest, "North West"},
		{dir::NorthWest, "North West"},
		{dir::north, "North"},
		{dir::North, "North"},
		{dir::northEast, "North East"},
		{dir::NorthEast, "North East"},
		{dir::up, "Up"},
		{dir::Up, "Up"},
		{dir::down, "Down"},
		{dir::Down, "Down"},
		
		{dir::STATE_COUNT, "STATE_COUNT"}
	} };

	enum class dir4
	{
		south = 0
		, South = 0
		, east = 1
		, East = 1
		, north = 2
		, North = 2
		, west = 3
		, West = 3

		, STATE_COUNT
	};
	const std::array<const EnumMapping::NameValuePair<dir4>, 9 > v_dir4{ {

		{dir4::south, "South"},
		{dir4::South, "South"},
		{dir4::east, "East"},
		{dir4::East, "East"},
		{dir4::north, "North"},
		{dir4::North, "North"},
		{dir4::west, "West"},
		{dir4::West, "West"},

		{dir4::STATE_COUNT, "STATE_COUNT"}
	} };

	enum class dir4_diag
	{	 
		 southWest = 0
		, SouthWest = 0
		, southEast = 1
		, SouthEast = 1
		, northEast = 2
		, NorthEast = 2
		, northWest = 3
		, NorthWest = 3

		, STATE_COUNT
	};
	const std::array<const EnumMapping::NameValuePair<dir4_diag>, 9 > v_dir4_diag{ {
		{dir4_diag::southWest, "South West"},
		{dir4_diag::SouthWest, "South West"},
		{dir4_diag::southEast, "South East"},
		{dir4_diag::SouthEast, "South East"},
		{dir4_diag::northEast, "North East"},
		{dir4_diag::NorthEast, "North East"},
		{dir4_diag::northWest, "North West"},
		{dir4_diag::NorthWest, "North West"},

		{dir4_diag::STATE_COUNT, "STATE_COUNT"}
	} };


	enum class dir6
	{			
		South = 0
		, East = 1
		, North = 2
		, West = 3
		, Up = 4
		, Down = 5
		
		, STATE_COUNT
	};
	const std::array<const EnumMapping::NameValuePair<dir6>, (int)dir6::STATE_COUNT + 1 > v_dir6{{

		{dir6::South, "South"},
		{dir6::East, "East"},
		{dir6::North, "North"},
		{dir6::West, "West"},
		{dir6::Up, "Up"},
		{dir6::Down, "Down"},

		{dir6::STATE_COUNT, "STATE_COUNT"}
	} };


	enum class z_orientation
	{
		FromBelow
		, SamePlane
		, FromAbove

		, STATE_COUNT
	};
	const std::array<const EnumMapping::NameValuePair<z_orientation>, (int)z_orientation::STATE_COUNT + 1 > v_z_orientation{ {

		{z_orientation::FromBelow, "FromBelow"},
		{z_orientation::SamePlane, "SamePlane"},
		{z_orientation::FromAbove, "FromAbove"},

		{z_orientation::STATE_COUNT, "STATE_COUNT"}
	} };

	//


	enum class dim
	{
		width = 0
		, X = 0
		, height = 1
		, Y = 1
		, depth = 2
		, Z = 2

		, STATE_COUNT
	};
	const std::array<const EnumMapping::NameValuePair<dim>, 7 > v_dim{ {
		{dim::width, "Width"},
		{dim::X, "X"},
		{dim::height, "height"},
		{dim::Y, "Y"},
		{dim::depth, "depth"},
		{dim::Z, "Z"},

		{dim::STATE_COUNT, "STATE_COUNT"}
	} };


	enum class dir3d
	{
		//0 no direction
		//	 down			same			up	
		//7	 8	9		15	16	17		24	25	26
		//4	 5	6		13	0	14		21	22	23
		//1	 2	3		10	11	12		18	19	20

		//1-9, down & sw,s,se,w,d,e,nw,n,ne
		//10-17, same level & sw,s,se,w,e,nw,n,ne
		//18-26, up & sw,s,se,w,up,e,nw,n,ne
		NoDirection = 0
		, DownSouthWest = 1
		, DownSouth = 2
		, DownSouthEast = 3
		, DownWest = 4
		, Down = 5
		, DownEast = 6
		, DownNorthWest = 7
		, DownNorth = 8
		, DownNorthEast = 9

		, SouthWest = 10
		, South = 11
		, SouthEast = 12
		, West = 13
		, East = 14
		, NorthWest = 15
		, North = 16
		, NorthEast = 17
		
		, UpSouthWest = 18
		, UpSouth = 19
		, UpSouthEast = 20
		, UpWest = 21
		, Up = 22
		, UpEast = 23
		, UpNorthWest = 24
		, UpNorth = 25
		, UpNorthEast = 26


		, STATE_COUNT
	};
	const std::array<const EnumMapping::NameValuePair<dir3d>, (int)dir3d::STATE_COUNT + 1 > v_dir3d{ {
		{dir3d::NoDirection, "No Direction"},
		{dir3d::DownSouthWest, "Down South West"},
		{dir3d::DownSouth, "Down South"},
		{dir3d::DownSouthEast, "Down South East"},
		{dir3d::DownWest, "Down West"},
		{dir3d::Down, "Down"},
		{dir3d::DownEast, "Down East"},
		{dir3d::DownNorthWest, "Down North West"},
		{dir3d::DownNorth, "Down North"},
		{dir3d::DownNorthEast, "Down North East"},

		{dir3d::SouthWest, "South West"},
		{dir3d::South, "South"},
		{dir3d::SouthEast, "South East"},
		{dir3d::West, "West"},
		{dir3d::East, "East"},
		{dir3d::NorthWest, "North West"},
		{dir3d::North, "North"},
		{dir3d::NorthEast, "North East"},

		{dir3d::UpSouthWest, "Up South West"},
		{dir3d::UpSouth, "Up South"},
		{dir3d::UpSouthEast, "Up South East"},
		{dir3d::UpWest, "Up West"},
		{dir3d::Up, "Up"},
		{dir3d::UpEast, "Up East"},
		{dir3d::UpNorthWest, "Up North West"},
		{dir3d::UpNorth, "Up North"},
		{dir3d::UpNorthEast, "Up North East"},

		{dir3d::STATE_COUNT, "STATE_COUNT"}
	} };

}

namespace Example
{
	enum AttackFlags
	{

		Contact = 1ul << 0,  // Move connects with target
		Projectile = 1ul << 1,  // Attack is projectile based
		Unblockable = 1ul << 2,  // Attack can not be blocked
		UncounterableLv1 = 1ul << 3,  // Attack can't be countered except by extreme counter attack skills/status effects
		UncounterableLv2 = 1ul << 4,  // Attack can not be countered
		Flinches = 1ul << 5,  // Has a chance to stun the enemy, pushing back their next turn
		Unreflectable = 1ul << 6,  // Attack penetrates reflect. Only checked for Magic attacks
		IgnoreDefenderStatusEffects = 1ul << 7,  // Ignores active status effects on the defender
		IgnoreAttackerStatusEffects = 1ul << 8,  // Ignores active status effects on the attacker
		IgnoreDefenderAbilities = 1ul << 9,  // Ignore the defenders abilities
		IgnoreAttackerAbilities = 1ul << 10,  // Ignore the attackers abilities
		IgnoreArmorRating = 1ul << 11,  // Ignore the defensive boosts of armor
		IgnoreWeaponRating = 1ul << 12,  // Ignore the attack boost from weapons
		HighCritical = 1ul << 13,  // The move has an increased chance to crit
		CausesStatus = 1ul << 14,  // Can the move cause status effects?
		Elemental = 1ul << 15,  // Is the move elemental based?
		Unimplemented = 1ul << 16,  // has the move been implemented yet?
		ModsTimer = 1ul << 17,  // Does it have an effect on the target or users timer?
		Heals = 1ul << 18,  // Does the move heal?
		SecondaryEffects = 1ul << 19,  // Attack has additional effects besides basic attack
		PhysicalAttackFlag = 1ul << 20,  // Is the Class Physically based? I.E. blocked by Protect and Shield
		MagicAttackFlag = 1ul << 21,  // Is the move Magically Based? I.E. is it affected by things like Shell
		MultiHit = 1ul << 22,  // Does it enxcapsulate more then 1 hit
		SingleUse = 1ul << 23,  // Attack can only be used once per battle
		DoesNotCauseDamage = 1ul << 24,

		MaskAttack = MagicAttackFlag | PhysicalAttackFlag,
		MaskIgnore = IgnoreWeaponRating | IgnoreArmorRating | IgnoreAttackerAbilities | IgnoreDefenderAbilities | IgnoreAttackerStatusEffects,
		// etc
	};

	static bool HasAttackFlag(AttackFlags flags)
	{
		return flags & MaskAttack;
	}

	static bool HasIgnoreFlag(AttackFlags flags)
	{
		return flags & MaskIgnore;
	}






}

namespace COMM
{

	enum class WORD_TYPE
	{	  
		UNSET = 0
		, WORD
		, WORD_NO_SPACE
		, NUMBER
		, NUMBER_NO_SPACE
		, PUNCTUATION
		, PUNCTUATION_NO_SPACE
		//words and number should be handled by a rectanglar (or whatever) string
		//, WORD_AND_NUMBER	

		, STATE_COUNT

	};
	const std::array<const EnumMapping::NameValuePair<WORD_TYPE>, 8 > v_WORD_TYPE{ {
		{WORD_TYPE::UNSET, "**Unset**"},

		{WORD_TYPE::WORD, "Word"},
		{ WORD_TYPE::WORD_NO_SPACE, "Word_NS" },
		{WORD_TYPE::NUMBER, "Number"},
		{ WORD_TYPE::NUMBER_NO_SPACE, "Number_NS" },
		{WORD_TYPE::PUNCTUATION, "Punctuation"},
		{ WORD_TYPE::PUNCTUATION_NO_SPACE, "Punctuation_NS" },

		{WORD_TYPE::STATE_COUNT, "STATE_COUNT"},
	} };

}

#endif