import pyCubbyFlow
import unittest

class Vector2F(unittest.TestCase):
	def testInit(self):
		a = pyCubbyFlow.Vector2F()
		self.assertEqual(a.x, 0.0)
		self.assertEqual(a.y, 0.0)
		b = pyCubbyFlow.Vector2F(1, 2)
		self.assertEqual(b.x, 1.0)
		self.assertEqual(b.y, 2.0)
		c = pyCubbyFlow.Vector2F(y = 2, x = 1)
		self.assertEqual(c.x, 1.0)
		self.assertEqual(c.y, 2.0)

	def testGetters(self):
		a = pyCubbyFlow.Vector2F(1, 2)
		self.assertEqual(a[0], 1)
		self.assertEqual(a[1], 2)

	def testSetters(self):
		a = pyCubbyFlow.Vector2F(1, 2)
		a[0] = 4; a[1] = 5;
		self.assertEqual(a[0], 4)
		self.assertEqual(a[1], 5)

	def testCalc(self):
		a = pyCubbyFlow.Vector2F(1, 2)
		b = pyCubbyFlow.Vector2F(4, 6)
		c = a + b
		self.assertEqual(c.x, 5.0)
		self.assertEqual(c.y, 8.0)
		c = a - b
		self.assertEqual(c.x, -3.0)
		self.assertEqual(c.y, -4.0)
		c = a * b
		self.assertEqual(c.x, 4.0)
		self.assertEqual(c.y, 12.0)
		c = a / b
		self.assertAlmostEqual(c.x, 1.0 / 4.0)
		self.assertAlmostEqual(c.y, 1.0 / 3.0)


class Vector2DTest(unittest.TestCase):
	def testInit(self):
		a = pyCubbyFlow.Vector2D()
		self.assertEqual(a.x, 0.0)
		self.assertEqual(a.y, 0.0)
		b = pyCubbyFlow.Vector2D(1, 2)
		self.assertEqual(b.x, 1.0)
		self.assertEqual(b.y, 2.0)
		c = pyCubbyFlow.Vector2D(y = 2, x = 1)
		self.assertEqual(c.x, 1.0)
		self.assertEqual(c.y, 2.0)

	def testGetters(self):
		a = pyCubbyFlow.Vector2D(1, 2)
		self.assertEqual(a[0], 1)
		self.assertEqual(a[1], 2)

	def testSetters(self):
		a = pyCubbyFlow.Vector2D(1, 2)
		a[0] = 4; a[1] = 5;
		self.assertEqual(a[0], 4)
		self.assertEqual(a[1], 5)

	def testCalc(self):
		a = pyCubbyFlow.Vector2D(1, 2)
		b = pyCubbyFlow.Vector2D(4, 6)
		c = a + b
		self.assertEqual(c.x, 5.0)
		self.assertEqual(c.y, 8.0)
		c = a - b
		self.assertEqual(c.x, -3.0)
		self.assertEqual(c.y, -4.0)
		c = a * b
		self.assertEqual(c.x, 4.0)
		self.assertEqual(c.y, 12.0)
		c = a / b
		self.assertAlmostEqual(c.x, 1.0 / 4.0)
		self.assertAlmostEqual(c.y, 1.0 / 3.0)

		
class Vector3FTest(unittest.TestCase):
	def testInit(self):
		a = pyCubbyFlow.Vector3F()
		self.assertEqual(a.x, 0.0)
		self.assertEqual(a.y, 0.0)
		self.assertEqual(a.z, 0.0)
		b = pyCubbyFlow.Vector3F(1, 2, 3)
		self.assertEqual(b.x, 1.0)
		self.assertEqual(b.y, 2.0)
		self.assertEqual(b.z, 3.0)
		c = pyCubbyFlow.Vector3F(y = 2, x = 1, z = 3)
		self.assertEqual(c.x, 1.0)
		self.assertEqual(c.y, 2.0)
		self.assertEqual(c.z, 3.0)

	def testGetters(self):
		a = pyCubbyFlow.Vector3F(1, 2, 3)
		self.assertEqual(a[0], 1)
		self.assertEqual(a[1], 2)
		self.assertEqual(a[2], 3)

	def testSetters(self):
		a = pyCubbyFlow.Vector3F(1, 2, 3)
		a[0] = 4; a[1] = 5; a[2] = 6
		self.assertEqual(a[0], 4)
		self.assertEqual(a[1], 5)
		self.assertEqual(a[2], 6)

	def testCalc(self):
		a = pyCubbyFlow.Vector3F(1, 2, 3)
		b = pyCubbyFlow.Vector3F(4, 6, 8)
		c = a + b
		self.assertEqual(c.x, 5.0)
		self.assertEqual(c.y, 8.0)
		self.assertEqual(c.z, 11.0)
		c = a - b
		self.assertEqual(c.x, -3.0)
		self.assertEqual(c.y, -4.0)
		self.assertEqual(c.z, -5.0)
		c = a * b
		self.assertEqual(c.x, 4.0)
		self.assertEqual(c.y, 12.0)
		self.assertEqual(c.z, 24.0)
		c = a / b
		self.assertAlmostEqual(c.x, 1.0 / 4.0)
		self.assertAlmostEqual(c.y, 1.0 / 3.0)
		self.assertAlmostEqual(c.z, 3.0 / 8.0)

class Vector3DTest(unittest.TestCase):
	def testInit(self):
		a = pyCubbyFlow.Vector3D()
		self.assertEqual(a.x, 0.0)
		self.assertEqual(a.y, 0.0)
		self.assertEqual(a.z, 0.0)
		b = pyCubbyFlow.Vector3D(1, 2, 3)
		self.assertEqual(b.x, 1.0)
		self.assertEqual(b.y, 2.0)
		self.assertEqual(b.z, 3.0)
		c = pyCubbyFlow.Vector3D(y = 2, x = 1, z = 3)
		self.assertEqual(c.x, 1.0)
		self.assertEqual(c.y, 2.0)
		self.assertEqual(c.z, 3.0)

	def testGetters(self):
		a = pyCubbyFlow.Vector3D(1, 2, 3)
		self.assertEqual(a[0], 1)
		self.assertEqual(a[1], 2)
		self.assertEqual(a[2], 3)

	def testSetters(self):
		a = pyCubbyFlow.Vector3D(1, 2, 3)
		a[0] = 4; a[1] = 5; a[2] = 6
		self.assertEqual(a[0], 4)
		self.assertEqual(a[1], 5)
		self.assertEqual(a[2], 6)

	def testCalc(self):
		a = pyCubbyFlow.Vector3D(1, 2, 3)
		b = pyCubbyFlow.Vector3D(4, 6, 8)
		c = a + b
		self.assertEqual(c.x, 5.0)
		self.assertEqual(c.y, 8.0)
		self.assertEqual(c.z, 11.0)
		c = a - b
		self.assertEqual(c.x, -3.0)
		self.assertEqual(c.y, -4.0)
		self.assertEqual(c.z, -5.0)
		c = a * b
		self.assertEqual(c.x, 4.0)
		self.assertEqual(c.y, 12.0)
		self.assertEqual(c.z, 24.0)
		c = a / b
		self.assertAlmostEqual(c.x, 1.0 / 4.0)
		self.assertAlmostEqual(c.y, 1.0 / 3.0)
		self.assertAlmostEqual(c.z, 3.0 / 8.0)

def main():
	pyCubbyFlow.Logging.mute()
	unittest.main()

if __name__ == '__main__':
	main()