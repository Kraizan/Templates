class SegTree {
	vector<int> seg;
public:
	SegTree(int n){
		seg.resize(4*n + 1);
	}
	void build(int ind, int low, int high, vector<int> &arr){
		if(low == high){
			seg[ind] = arr[low];
			return;
		}
		
		int mid = (low + high) / 2;
		build(2*ind+1, low, mid, arr);
		build(2*ind+2, mid+1, high, arr);
		
		seg[ind] = seg[2*ind+1] + seg[2*ind+2];
	}
	void update(int ind, int low, int high, int i, int val){
		if(low == high){
			seg[ind] = val;
			return;
		}
		
		int mid = (low + high) / 2;
		if(i <= mid) update(2*ind+1, low, mid, i, val);
		else update(2*ind+2, mid+1, high, i, val);
		
		seg[ind] = seg[2*ind+1] + seg[2*ind+2];
	}
	int query(int ind, int low, int high, int l, int r){
		if(low > r || high < l){
			return 0;
		}
		else if(low >= l && high <= r){
			return seg[ind];
		}
		else{
			int mid = (low + high)/2;
			return query(2*ind+1, low, mid, l, r) + query(2*ind+2, mid+1, high, l, r);
		}
	}
};
