Test:y_bitmap_Fade2()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(64, 64);
	for (new y = 0; y != 64; ++y)
	{
		for (new x = 0; x != 64; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | (y * 4));
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | (x * 4));
		}
	}
	Bitmap_Write(ctx, "y_bitmap_Fade2.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Fade1()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(64, 64);
	for (new y = 0; y != 64; ++y)
	{
		for (new x = 0; x != 64; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | (x * y * 256 / (64 * 64)));
		}
	}
	Bitmap_Write(ctx, "y_bitmap_Fade1.bmp");
	Bitmap_Destroy(ctx);
}

