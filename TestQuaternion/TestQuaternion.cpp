#include "CppUnitTest.h"

#include "Quaternion.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestQuaternion
{
	TEST_CLASS(TestQuaternion)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			Quaternion q_4floats(0.0f, 1.0f, 2.0f, 3.0f);
			Assert::AreEqual(0.0f, q_4floats.w);
			Assert::AreEqual(1.0f, q_4floats.x);
			Assert::AreEqual(2.0f, q_4floats.y);
			Assert::AreEqual(3.0f, q_4floats.z);

			Quaternion q_vector3(Vector3(4.0f, 5.0f, 6.0f));
			Assert::AreEqual(0.0f, q_vector3.w);
			Assert::AreEqual(4.0f, q_vector3.x);
			Assert::AreEqual(5.0f, q_vector3.y);
			Assert::AreEqual(6.0f, q_vector3.z);

			Quaternion q_floatvector3(7.0f, Vector3(8.0f, 9.0f, 10.0f));
			Assert::AreEqual(7.0f, q_floatvector3.w);
			Assert::AreEqual(8.0f, q_floatvector3.x);
			Assert::AreEqual(9.0f, q_floatvector3.y);
			Assert::AreEqual(10.0f, q_floatvector3.z);
		}

		TEST_METHOD(Equals)
		{
			Quaternion q_1(0.0f, 1.0f, 2.0f, 3.0f);
			Quaternion q_2(0.0f, 1.0f, 2.0f, 3.0f);
			Quaternion q_3(4.0f, 4.0f, 4.0f, 4.0f);

			Assert::IsTrue(q_1 == q_2);
			Assert::IsFalse(q_1 == q_3);
		}

		TEST_METHOD(FloatMult)
		{
			Quaternion q_base(0.0f, 1.0f, 2.0f, 3.0f);
			Quaternion q_mult = q_base * 2.0f;
			Assert::AreEqual(0.0f, q_mult.w);
			Assert::AreEqual(2.0f, q_mult.x);
			Assert::AreEqual(4.0f, q_mult.y);
			Assert::AreEqual(6.0f, q_mult.z);

			q_mult *= 3.0f;
			Assert::AreEqual(0.0f, q_mult.w);
			Assert::AreEqual(6.0f, q_mult.x);
			Assert::AreEqual(12.0f, q_mult.y);
			Assert::AreEqual(18.0f, q_mult.z);
		}

		TEST_METHOD(QuatMult)
		{
			Vector3 v_1 = Vector3(1.0f, 2.0f, 3.0f);
			Vector3 v_2 = Vector3(5.0f, 6.0f, 7.0f);
			Quaternion q_1(0.0f, v_1);
			Quaternion q_2(4.0f, v_2);
			Quaternion q_mult = q_1 * q_2;

			float w = q_1.w * q_2.w - Vector3::dot(v_1, v_2);
			Vector3 xyz_comp = q_1.w * v_2 + q_2.w * v_1 + Vector3::cross(v_1, v_2);
			Assert::AreEqual(w, q_mult.w);
			Assert::AreEqual(xyz_comp.x, q_mult.x);
			Assert::AreEqual(xyz_comp.y, q_mult.y);
			Assert::AreEqual(xyz_comp.z, q_mult.z);

			q_1 *= q_2;
			Assert::IsTrue(q_mult == q_1);
		}

		TEST_METHOD(QuatAdd)
		{
			Quaternion q_1(0.0f, 1.0f, 2.0f, 3.0f);
			Quaternion q_2(4.0f, 5.0f, 6.0f, 7.0f);
			Quaternion q_add = q_1 + q_2;
			Assert::AreEqual(4.0f, q_add.w);
			Assert::AreEqual(6.0f, q_add.x);
			Assert::AreEqual(8.0f, q_add.y);
			Assert::AreEqual(10.0f, q_add.z);

			q_add += q_2;
			Assert::AreEqual(8.0f, q_add.w);
			Assert::AreEqual(11.0f, q_add.x);
			Assert::AreEqual(14.0f, q_add.y);
			Assert::AreEqual(17.0f, q_add.z);
		}

		TEST_METHOD(QuatSub)
		{
			Quaternion q_1(0.0f, 1.0f, 2.0f, 3.0f);
			Quaternion q_2(4.0f, 5.0f, 6.0f, 7.0f);
			Quaternion q_add = q_1 - q_2;
			Assert::AreEqual(-4.0f, q_add.w);
			Assert::AreEqual(-4.0f, q_add.x);
			Assert::AreEqual(-4.0f, q_add.y);
			Assert::AreEqual(-4.0f, q_add.z);

			q_add -= q_2;
			Assert::AreEqual(-8.0f, q_add.w);
			Assert::AreEqual(-9.0f, q_add.x);
			Assert::AreEqual(-10.0f, q_add.y);
			Assert::AreEqual(-11.0f, q_add.z);
		}

		TEST_METHOD(QuatOpp)
		{
			Quaternion q(-1.0f, 1.0f, 2.0f, 3.0f);
			Quaternion q_opp = -q;

			Assert::AreEqual(1.0f, q_opp.w);
			Assert::AreEqual(-1.0f, q_opp.x);
			Assert::AreEqual(-2.0f, q_opp.y);
			Assert::AreEqual(-3.0f, q_opp.z);
		}

		TEST_METHOD(Conj)
		{
			Quaternion q(-1.0f, 1.0f, 2.0f, 3.0f);
			Quaternion q_conj = Quaternion::conj(q);

			Assert::AreEqual(-1.0f, q_conj.w);
			Assert::AreEqual(-1.0f, q_conj.x);
			Assert::AreEqual(-2.0f, q_conj.y);
			Assert::AreEqual(-3.0f, q_conj.z);
		}

		TEST_METHOD(QuatDiff)
		{
			Quaternion q_1(0.0f, 1.0f, 2.0f, 3.0f);
			Quaternion q_2(4.0f, 5.0f, 6.0f, 7.0f);
			Quaternion q_diff = Quaternion::diff(q_1, q_2);
			Quaternion q_wanted = q_1 * Quaternion::conj(q_2);
			Assert::AreEqual(q_wanted.w, q_diff.w);
			Assert::AreEqual(q_wanted.x, q_diff.x);
			Assert::AreEqual(q_wanted.y, q_diff.y);
			Assert::AreEqual(q_wanted.z, q_diff.z);
		}

		TEST_METHOD(QuatInv)
		{
			Quaternion q(2.0f, 2.0f, 2.0f, 2.0f);
			Quaternion q_inv = Quaternion::inv(q);
			float norm = 4.0f;

			Assert::AreEqual(2.0f / norm, q_inv.w);
			Assert::AreEqual(-2.0f / norm, q_inv.x);
			Assert::AreEqual(-2.0f / norm, q_inv.y);
			Assert::AreEqual(-2.0f / norm, q_inv.z);
		}

		TEST_METHOD(Norm)
		{
			Quaternion q(0.0f, 1.0f, 2.0f, 3.0f);
			float norm2 = 0.0f + 1.0f + 4.0f + 9.0f;
			Assert::AreEqual(sqrtf(norm2), Quaternion::norm(q));

			Assert::AreEqual(norm2, Quaternion::norm2(q));
		}

		TEST_METHOD(InvNorm)
		{
			Quaternion q(0.0f, 1.0f, 2.0f, 3.0f);
			float norm = sqrtf(0.0f + 1.0f + 4.0f + 9.0f);
			Assert::AreEqual(1.0f / norm, Quaternion::inv_norm(q));
		}

		TEST_METHOD(QuatNorm)
		{
			Quaternion q(0.0f, 1.0f, 2.0f, 3.0f);
			float norm = sqrtf(0.0f + 1.0f + 4.0f + 9.0f);
			Quaternion q_norm = Quaternion::normalize(q);

			Assert::AreEqual(0.0f / norm, q_norm.w);
			Assert::AreEqual(1.0f / norm, q_norm.x);
			Assert::AreEqual(2.0f / norm, q_norm.y);
			Assert::AreEqual(3.0f / norm, q_norm.z);
		}

		TEST_METHOD(Dot)
		{
			Quaternion q_1(0.0f, 1.0f, 2.0f, 3.0f);
			Quaternion q_2(4.0f, 5.0f, 6.0f, 7.0f);
			float dot = 0.0f + 5.0f + 12.0f + 21.0f;
			Assert::AreEqual(dot, Quaternion::dot(q_1, q_2));
		}

		TEST_METHOD(QuatExp)
		{
			Quaternion q(0.5f, 2.0f, 1.0f, 0.0f);
			float t = 1.5f;
			Quaternion q_exp = Quaternion::exp(q, t);

			float alpha = std::acos(0.5f);
			Vector3 xyz = Vector3(2.0f, 1.0f, 0.0f) * (std::sin(t * alpha) / std::sin(alpha));

			Assert::AreEqual(std::cos(t * alpha), q_exp.w);
			Assert::AreEqual(xyz.x, q_exp.x);
			Assert::AreEqual(xyz.y, q_exp.y);
			Assert::AreEqual(xyz.z, q_exp.z);
		}

		//TEST_METHOD(QuatExpZero)
		//{
		//	Quaternion q(-1.0f, 2.0f, 1.0f, 0.0f);
		//	float t = 1.5f;
		//	Quaternion q_exp = Quaternion::exp(q, t);
		//
		//	Assert::AreEqual(0.0f, q_exp.w);
		//	Assert::AreEqual(0.0f, q_exp.x);
		//	Assert::AreEqual(0.0f, q_exp.y);
		//	Assert::AreEqual(0.0f, q_exp.z);
		//}

		TEST_METHOD(RetVector3)
		{
			Quaternion q(0.0f, 1.0f, 2.0f, 3.0f);
			Assert::IsTrue(Vector3(1.0f, 2.0f, 3.0f) == q.toVector3());
			Assert::IsTrue(Vector3(1.0f, 2.0f, 3.0f) == Quaternion::toVector3(q));
		}
	};
}
