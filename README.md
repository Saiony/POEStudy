# POEStudy
This project is a study on recreating the Leap Slam ability from Path of Exile inside Unreal Engine 5.5, built on top of the Gameplay Ability System (GAS).

The goal was to faithfully replicate the core behavior of the skill as described in the official wiki: the character leaps through the air in an arc toward a target location, can cross small gaps and obstacles, deals AoE damage on landing, and has its speed scaled by the AttackSpeed attribute.

This project is also a good practical reference for anyone looking to understand GAS, as it makes use of a wide range of its systems: Gameplay Abilities, Gameplay Effects, Gameplay Cues, Gameplay Attributes, Gameplay Tags, and Attribute Sets, all working together in a real gameplay context.

The project uses the Top-Down template as a base and extends it with a GAS setup designed to be easy to expand into a full ARPG.

# Character Rotation & Responsiveness
Responsiveness is a key part of the game feel in an ARPG. When an ability starts, the player character rotates instantly to face the target direction instead of using an interpolated (smooth) rotation. This gives the player more precise control and feels better, and it goes unnoticed because the attack animation starts right after.

# HUD & UI
The game includes a simple UI displayed above each character's head, used only for informational purposes, showing gameplay attributes and any active gameplay effects applied to them (like the stun effect). The binding was kept simple and does not use a robust communication architecture like MVVM, purely for the sake of brevity and the limited time available for this test.

# VFX & SFX
The sound and visual effects are not placed directly inside the animation montage. In a game of this type, it is very common to want to change effects and sounds based on some parameter. For example, the sound might need to change depending on the type of terrain hit, or the damage particle might change based on the ability level or equipment.

For audio, MetaSound was used because it accepts parameters and supports internal logic, such as varying the sound based on terrain, whether an enemy was hit, whether the hit was a critical strike, and so on. MetaSound also allows pitch variation on each new instance, which makes the sound less repetitive over time.
Both SFX and VFX are placed inside a Gameplay Cue, which automatically replicates to clients. In a single-player game, this has no downside.

# Max Range Shape
A circle was used for the maximum range shape. Only 3 skills in Path of Exile use a square shape, and as the wiki itself notes, this is considered unusual behavior. This was actually corrected in Path of Exile 2, which uses a radius-based distance for all skills.

# Jump Arc & Animation Montage
Since the jump can have variable duration, the animation montage was split into sections. The character plays the jump start, then loops the in-air animation until it reaches the target, and then plays the landing section. This may seem unnecessary given the durations seen in Path of Exile, but in real game development, parameters change frequently, and this structure allows the ability to scale cleanly with any duration.

The jump duration is also the same regardless of the distance traveled. Because of this, it is not possible to use LaunchCharacter combined with SuggestProjectileVelocityCustomArc to calculate the velocity. The solution was to use a Curve with a Timeline to simulate the arc movement manually.

# Attack Duration Formula
The attack duration formula in Path of Exile involves several variables that were not implemented in this project. For this reason, the formula was simplified to take only the AttackSpeed attribute into account.

# Input System
To bind abilities to inputs, a system was created where a Data Asset represents an ability. This asset can contain multiple Gameplay Abilities, Gameplay Effects, and attributes (useful for passive abilities). When an ability is granted, a Gameplay Tag is also passed in, and this tag is linked to an input action.
This is essentially a simplified version of how Lyra implements Gameplay Abilities through equipment, but registering directly via Gameplay Tag since equipment does not define the abilities here, and any ability can be assigned to any input.
