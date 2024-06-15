namespace Zee.Common
{
    public static class ArrayExtensions
    {
        public static void StableSort<T>(this IList<T> values, Comparison<T> comparison)
        {
            var keys = new KeyValuePair<int, T>[values.Count];
            for (int i = 0; i < values.Count; i++)
            {
                keys[i] = new KeyValuePair<int, T>(i, values[i]);
            }

            Array.Sort(keys, (x, y) => comparison(x.Value, y.Value));

            for (int i = 0; i < values.Count; i++)
            {
                values[i] = keys[i].Value;
            }
        }
    }
}
